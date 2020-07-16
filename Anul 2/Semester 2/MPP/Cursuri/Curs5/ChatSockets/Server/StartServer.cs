using System;
using System.Net.Sockets;

using System.Threading;
using chat.persistence.repository.mock;
using chat.persistence;
using chat.services;
using chat.network.client;
using chat.persistence.repository.db;
using ServerTemplate;
namespace chat
{
    using server;
    class StartServer
    {
        static void Main(string[] args)
        {
            
           // IUserRepository userRepo = new UserRepositoryMock();
          //  IUserRepository userRepo=new UserRepositoryDb();
           // IMessageRepository messageRepository=new MessageRepositoryDb();
            IUserRepository userRepo=new UserRepositoryMock();
            IMessageRepository messageRepository=new MessageRepositoryMock();
            IChatServices serviceImpl = new ChatServerImpl(userRepo, messageRepository);

           // IChatServer serviceImpl = new ChatServerImpl();
			SerialChatServer server = new SerialChatServer("127.0.0.1", 55555, serviceImpl);
            server.Start();
            Console.WriteLine("Server started ...");
            //Console.WriteLine("Press <enter> to exit...");
            Console.ReadLine();
            
        }
    }

    public class SerialChatServer: ConcurrentServer 
    {
        private IChatServices server;
        private ChatClientWorker worker;
        public SerialChatServer(string host, int port, IChatServices server) : base(host, port)
            {
                this.server = server;
                Console.WriteLine("SerialChatServer...");
        }
        protected override Thread createWorker(TcpClient client)
        {
            worker = new ChatClientWorker(server, client);
            return new Thread(new ThreadStart(worker.run));
        }
    }
    
}
