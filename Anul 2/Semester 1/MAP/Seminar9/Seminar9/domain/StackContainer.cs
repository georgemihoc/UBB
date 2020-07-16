namespace Seminar9.domain
{
    public class StackContainer:IContainer
    {
        private Task[] tasks;
        private int size;

        public StackContainer(Task[] t)
        {
            tasks = new Task[100];
            size = 0;
        }

        public Task Remove()
        {
            throw new System.NotImplementedException();
        }

        public void Add(Task task)
        {
            tasks[size++] = task;
        }

        public int Size
        {
            get => size;
            set => size = value;
        }

        public bool isEmpty()
        {
            throw new System.NotImplementedException();
        }
        
    }
}