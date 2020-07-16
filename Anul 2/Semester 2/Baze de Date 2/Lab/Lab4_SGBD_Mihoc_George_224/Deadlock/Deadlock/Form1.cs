using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Deadlock
{
    public partial class Form1 : Form
    {
        SqlDataAdapter dataAdaptor = new SqlDataAdapter();
        DataSet dataSet = new DataSet();
        static string con = ConfigurationManager.ConnectionStrings["connection"].ConnectionString;
        SqlConnection connection = new SqlConnection(con);
        int incercari = 5;
        SqlTransaction transaction;
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {
                string query = ConfigurationSettings.AppSettings["transaction"];
                SqlCommand cmd = new SqlCommand(query, connection);
                connection.Open();
                transaction = connection.BeginTransaction();
                cmd.Transaction = transaction;
                cmd.ExecuteNonQuery();
                transaction.Commit();
                Console.WriteLine("Transaction commited");
            }
            catch (SqlException ex)
            {
              
                if (incercari > 0)
                {
                    incercari--;
                    transaction.Rollback();
                    MessageBox.Show(incercari + " incercari ramase");
                }
                else
                {
                    MessageBox.Show("ABORTED");
                    button1.Enabled = false;
                }
              
            }
            finally
            {
                connection.Close();
            }

        }
    }
}
