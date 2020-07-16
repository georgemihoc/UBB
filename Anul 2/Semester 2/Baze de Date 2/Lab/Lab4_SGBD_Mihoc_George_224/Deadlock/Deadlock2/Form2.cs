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

namespace Deadlock2
{
    public partial class Form2 : Form

    {
        SqlDataAdapter dataAdaptor = new SqlDataAdapter();
        DataSet dataSet = new DataSet();
        static string con = ConfigurationManager.ConnectionStrings["connection"].ConnectionString;
        SqlConnection connection = new SqlConnection(con);
        int incercari = 5;
        SqlTransaction transaction;

        public Form2()
        {
            InitializeComponent();
        }

        private void Form2_Load(object sender, EventArgs e)
        {

        }

        private void transaction1Handle(object sender, EventArgs e)
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
                Console.WriteLine("transaction commited");
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
