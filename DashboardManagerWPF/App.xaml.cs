using System.ComponentModel;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Windows;
using System.Windows.Controls;
using Hardcodet.Wpf.TaskbarNotification;

namespace DashboardManagerWPF
{
    /// <summary>
    /// Interaction logic for App.xaml
    /// </summary>
    public partial class App : Application
    {
        private TaskbarIcon notifyIcon;

        protected override void OnStartup(StartupEventArgs e)
        {
            base.OnStartup(e);

            notifyIcon = new TaskbarIcon();

            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "\"C:\\Class_Dashboard\\MainLauncher.exe\"";
            startInfo.Verb = "runas";
            try
            {
                Process.Start(startInfo);
            }
            catch
            {
                MessageBox.Show("Launch failed", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }

            // 从资源中加载图标
            using (Stream iconStream = Application.GetResourceStream(new Uri("pack://application:,,,/Resources/EditK.ico")).Stream)
            {
                notifyIcon.Icon = new Icon(iconStream);
            }

            notifyIcon.ToolTipText = "Dashboard Manager";
            notifyIcon.LeftClickCommand = new DelegateCommand(() =>
            {
                // 在这里创建和显示主窗口
                if (MainWindow == null)
                {
                    MainWindow = new MainWindow();
                    MainWindow.Closing += MainWindow_Closing;
                }
                MainWindow.Show();
                MainWindow.WindowState = WindowState.Normal;
            });

            // 创建上下文菜单
            var contextMenu = new ContextMenu();

            // 创建 "Exit Manager" 菜单项
            var menuExitItem = new MenuItem
            {
                Header = "Exit Manager",
            };
            menuExitItem.Click += (sender, args) =>
            {
                // 在这里处理 "Exit Manager" 菜单项的点击事件
                Application.Current.Shutdown();
            };

            // 将 "Exit Manager" 菜单项添加到上下文菜单中
            contextMenu.Items.Add(menuExitItem);

            // 将上下文菜单添加到托盘图标中
            notifyIcon.ContextMenu = contextMenu;
        }



        private void MainWindow_Closing(object sender, CancelEventArgs e)
        {
            e.Cancel = true;
            MainWindow.Hide();
        }

        protected override void OnExit(ExitEventArgs e)
        {
            notifyIcon.Dispose();  // 清理托盘图标
            base.OnExit(e);
        }
    }

    public class DelegateCommand : System.Windows.Input.ICommand
    {
        private readonly Action _action;

        public DelegateCommand(Action action)
        {
            _action = action;
        }

        public bool CanExecute(object parameter)
        {
            return true;
        }

        public void Execute(object parameter)
        {
            _action();
        }

        public event EventHandler CanExecuteChanged;
    }
}
