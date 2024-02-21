using System.Diagnostics;
using System.Windows;

namespace DashboardManagerWPF
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Chinese_Click(object sender, RoutedEventArgs e)
        {
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "\"C:\\Class_Dashboard\\ChangeMode.exe\"";
            startInfo.Arguments = "Chinese";
            startInfo.Verb = "runas";
            try
            {
                Process.Start(startInfo);
            }
            catch
            {
                MessageBox.Show("Set exam subject failed!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }
        private void Math_Click(object sender, RoutedEventArgs e)
        {
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "\"C:\\Class_Dashboard\\ChangeMode.exe\"";
            startInfo.Arguments = "Math";
            startInfo.Verb = "runas";
            try
            {
                Process.Start(startInfo);
            }
            catch
            {
                MessageBox.Show("Set exam subject failed!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }
        private void English_Click(object sender, RoutedEventArgs e)
        {
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "\"C:\\Class_Dashboard\\ChangeMode.exe\"";
            startInfo.Arguments = "English";
            startInfo.Verb = "runas";
            try
            {
                Process.Start(startInfo);
            }
            catch
            {
                MessageBox.Show("Set exam subject failed!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }
        private void Physics_Click(object sender, RoutedEventArgs e)
        {
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "\"C:\\Class_Dashboard\\ChangeMode.exe\"";
            startInfo.Arguments = "Physics";
            startInfo.Verb = "runas";
            try
            {
                Process.Start(startInfo);
            }
            catch
            {
                MessageBox.Show("Set exam subject failed!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }
        private void Chemistry_Click(object sender, RoutedEventArgs e)
        {
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "\"C:\\Class_Dashboard\\ChangeMode.exe\"";
            startInfo.Arguments = "Chemistry";
            startInfo.Verb = "runas";
            try
            {
                Process.Start(startInfo);
            }
            catch
            {
                MessageBox.Show("Set exam subject failed!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }
        private void Politics_Click(object sender, RoutedEventArgs e)
        {
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "\"C:\\Class_Dashboard\\ChangeMode.exe\"";
            startInfo.Arguments = "Politics";
            startInfo.Verb = "runas";
            try
            {
                Process.Start(startInfo);
            }
            catch
            {
                MessageBox.Show("Set exam subject failed!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }
        private void History_Click(object sender, RoutedEventArgs e)
        {
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "\"C:\\Class_Dashboard\\ChangeMode.exe\"";
            startInfo.Arguments = "History";
            startInfo.Verb = "runas";
            try
            {
                Process.Start(startInfo);
            }
            catch
            {
                MessageBox.Show("Set exam subject failed!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }
        private void None_Click(object sender, RoutedEventArgs e)
        {
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "\"C:\\Class_Dashboard\\ChangeMode.exe\"";
            startInfo.Arguments = "None";
            startInfo.Verb = "runas";
            try
            {
                Process.Start(startInfo);
            }
            catch
            {
                MessageBox.Show("Set exam subject failed!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }
        private void Edit_Click(object sender, RoutedEventArgs e)
        {
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "notepad.exe";
            startInfo.Arguments = "C:\\Class_Dashboard\\n_config.ini";
            startInfo.Verb = "runas";
            try
            {
                Process.Start(startInfo);
            }
            catch
            {
                MessageBox.Show("Open config file failed!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }
        private void Reload_Click(object sender, RoutedEventArgs e)
        {
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "\"C:\\Class_Dashboard\\Rainmeter\\RestartRainmeter.exe\"";
            startInfo.Verb = "runas";
            try
            {
                Process.Start(startInfo);
            }
            catch
            {
                MessageBox.Show("Reload failed!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }
        private void Reset_Click(object sender, RoutedEventArgs e)
        {
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "\"C:\\Class_Dashboard\\MainLauncher.exe\"";
            startInfo.Verb = "runas";
            try
            {
                Process.Start(startInfo);
            }
            catch
            {
                MessageBox.Show("Reset failed", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }
        private void Close_Click(object sender, RoutedEventArgs e)
        {
            this.Hide();
        }
        private void Exit_Click(object sender, RoutedEventArgs e)
        {
            ProcessStartInfo startInfo = new ProcessStartInfo();
            startInfo.FileName = "taskkill";
            startInfo.Arguments = "/f /im Rainmeter.exe";
            startInfo.Verb = "runas";
            try
            {
                Process.Start(startInfo);
            }
            catch
            {
                MessageBox.Show("Exit failed!", "Error", MessageBoxButton.OK, MessageBoxImage.Error);
            }
            Application.Current.Shutdown(0);
        }
    }
}