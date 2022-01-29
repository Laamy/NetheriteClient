using Netherite.Handlers;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Netherite
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            Task.Factory.StartNew(() => {
                Thread.Sleep(1);

                Invoke((MethodInvoker)delegate {
                    Hide();
                });
            });

            NetheriteTrayIcon.InitializeLifetimeService();
        }

        string path;

        private void toolStripMenuItem1_Click(object sender, EventArgs e) => Process.GetCurrentProcess().Kill();

        private void locateDLLToolStripMenuItem_Click(object sender, EventArgs e)
        {
            OpenFileDialog FileIn = new OpenFileDialog();
            if (FileIn.ShowDialog() == DialogResult.OK)
                if (FileIn.SafeFileName.ToLower().EndsWith(".dll"))
                    path = FileIn.FileName;
        }

        private void injectDLLToolStripMenuItem_Click(object sender, EventArgs e)
        {
            if (path != null)
                InjectionHandler.InjectDLL(path, "Minecraft.Windows");
        }
    }
}
