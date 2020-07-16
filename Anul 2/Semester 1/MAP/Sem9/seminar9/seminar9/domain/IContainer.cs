using System;
using System.Collections.Generic;
using System.Text;

namespace seminar9.domain
{
    //in C#, numele interfetelor incep cu I (conventie)
    interface IContainer
    {
        Task Remove();
        /// <summary>
        /// 
        /// </summary>
        /// <param name="task"></param>
        void Add(Task task);
        int Size { get; set; } //by default o proprietate din interfata este publica
        bool IsEmpty();

        Task this[Predicate<Task> index]
        {
            get;
            set;
        }
    }
}
