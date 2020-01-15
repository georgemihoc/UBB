using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace seminar9.domain
{
    class StackContainer : IContainer
    {
        private List<Task> tasks;
//        Task[] tasks;
        int size;
        public StackContainer()
        {
            tasks = new List<Task>();
//            tasks = new Task[100];
//            size = 0;
        }

        public int Size { get => size; set => size=value; }

        public void Add(Task task)
        {
            //normal ar trebui verificat daca e plin containerul si sa se faca resie
//            tasks[size++] = task;
            tasks.Add(task);
        }

        public bool IsEmpty()
        {
            return Size == 0;
        }

        public Task this[Predicate<Task> index]
        {
            get => throw new NotImplementedException();
            set => throw new NotImplementedException();
        }

        public Task Remove()
        {
            Task removed = tasks[tasks.Count - 1];
            tasks.RemoveAt(tasks.Count - 1);
            return removed;
//            Task task = tasks[size - 1];
//            tasks[size - 1] = null;
//            size--;
//            return task;
        }


        //vezi curs9 INDEXATORI
        public Task this[int index] 
        { get 
            { 
                return tasks.ElementAt(index); 
            } 
          set 
            { 
                tasks.Insert(index,value);
            } 
        }
    }
}
