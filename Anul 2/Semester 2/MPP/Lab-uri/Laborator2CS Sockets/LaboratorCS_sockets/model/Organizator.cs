namespace swim.model
{
    public class Organizator
    {
        private int idOrganizator;
        private string username;
        private string password;

        public Organizator(int idOrganizator, string username, string password)
        {
            this.idOrganizator = idOrganizator;
            this.username = username;
            this.password = password;
        }

        public int IdOrganizator
        {
            get => idOrganizator;
            set => idOrganizator = value;
        }

        public string Username
        {
            get => username;
            set => username = value;
        }

        public string Password
        {
            get => password;
            set => password = value;
        }
    }
}