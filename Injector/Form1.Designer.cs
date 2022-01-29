
namespace Netherite
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.NetheriteTrayIcon = new System.Windows.Forms.NotifyIcon(this.components);
            this.injectNetheriteToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator2 = new System.Windows.Forms.ToolStripSeparator();
            this.injectDLLToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.locateDLLToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStripSeparator3 = new System.Windows.Forms.ToolStripSeparator();
            this.toolStripMenuItem1 = new System.Windows.Forms.ToolStripMenuItem();
            this.contextMenuStrip1 = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.contextMenuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // NetheriteTrayIcon
            // 
            this.NetheriteTrayIcon.ContextMenuStrip = this.contextMenuStrip1;
            this.NetheriteTrayIcon.Icon = ((System.Drawing.Icon)(resources.GetObject("NetheriteTrayIcon.Icon")));
            this.NetheriteTrayIcon.Text = "Netherite Client";
            this.NetheriteTrayIcon.Visible = true;
            // 
            // injectNetheriteToolStripMenuItem
            // 
            this.injectNetheriteToolStripMenuItem.Name = "injectNetheriteToolStripMenuItem";
            this.injectNetheriteToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.injectNetheriteToolStripMenuItem.Text = "Inject";
            // 
            // toolStripSeparator2
            // 
            this.toolStripSeparator2.Name = "toolStripSeparator2";
            this.toolStripSeparator2.Size = new System.Drawing.Size(177, 6);
            // 
            // injectDLLToolStripMenuItem
            // 
            this.injectDLLToolStripMenuItem.Name = "injectDLLToolStripMenuItem";
            this.injectDLLToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.injectDLLToolStripMenuItem.Text = "Inject DLL";
            this.injectDLLToolStripMenuItem.Click += new System.EventHandler(this.injectDLLToolStripMenuItem_Click);
            // 
            // locateDLLToolStripMenuItem
            // 
            this.locateDLLToolStripMenuItem.Name = "locateDLLToolStripMenuItem";
            this.locateDLLToolStripMenuItem.Size = new System.Drawing.Size(180, 22);
            this.locateDLLToolStripMenuItem.Text = "Locate DLL";
            this.locateDLLToolStripMenuItem.Click += new System.EventHandler(this.locateDLLToolStripMenuItem_Click);
            // 
            // toolStripSeparator3
            // 
            this.toolStripSeparator3.Name = "toolStripSeparator3";
            this.toolStripSeparator3.Size = new System.Drawing.Size(177, 6);
            // 
            // toolStripMenuItem1
            // 
            this.toolStripMenuItem1.Name = "toolStripMenuItem1";
            this.toolStripMenuItem1.Size = new System.Drawing.Size(180, 22);
            this.toolStripMenuItem1.Text = "Exit";
            this.toolStripMenuItem1.Click += new System.EventHandler(this.toolStripMenuItem1_Click);
            // 
            // contextMenuStrip1
            // 
            this.contextMenuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.injectNetheriteToolStripMenuItem,
            this.toolStripSeparator2,
            this.injectDLLToolStripMenuItem,
            this.locateDLLToolStripMenuItem,
            this.toolStripSeparator3,
            this.toolStripMenuItem1});
            this.contextMenuStrip1.Name = "contextMenuStrip1";
            this.contextMenuStrip1.Size = new System.Drawing.Size(181, 126);
            this.contextMenuStrip1.Text = "Netherite Launcher";
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Name = "Form1";
            this.contextMenuStrip1.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.NotifyIcon NetheriteTrayIcon;
        private System.Windows.Forms.ContextMenuStrip contextMenuStrip1;
        private System.Windows.Forms.ToolStripMenuItem injectNetheriteToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator2;
        private System.Windows.Forms.ToolStripMenuItem injectDLLToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem locateDLLToolStripMenuItem;
        private System.Windows.Forms.ToolStripSeparator toolStripSeparator3;
        private System.Windows.Forms.ToolStripMenuItem toolStripMenuItem1;
    }
}

