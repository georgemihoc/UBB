namespace Seminar9.domain
{
    public abstract class Task
    {
        private int id;
        private string descriere;
        
        protected Task(int id, string descriere)
        {
            this.id = id;
            this.descriere = descriere;
        }

        protected Task()
        {
            throw new System.NotImplementedException();
        }


        public int Id
        {
            get => id;
            set => id = value;
        }

        public string Descriere
        {
            get => descriere;
            set => descriere = value;
        }

        public abstract void Execute();

        public override string ToString()
        {
            return id + " " + descriere;
        }
    }
}