using System;
using System.Collections.Generic;
using System.Text;

namespace seminar9.domain
{
    interface ITaskRunner
    {
        void executeOneTask(); //executa un task din colecţia de task-uri de executat      
        void executeAll();  //executǎ toate task-urile din colecţia de task-uri.     
        /// <summary>
        ///  adaugǎ un task în colecţia de task-uri de executat   
        /// </summary>
        /// <param name="t"></param>
        void addTask(Task t);
        Boolean hasTask();//verifica daca mai sunt task-ri de executat 
    }
}
