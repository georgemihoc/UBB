namespace Seminar9.domain
{
    interface IContainer
    {
        Task Remove();
        void Add(Task t);
        int Size { get; set; }
        bool isEmpty();

    }
    
}