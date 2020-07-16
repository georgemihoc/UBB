using System;
using System.Collections;
using System.Collections.Generic;
using System.Net.Sockets;

using System.Text;
using System.Threading;
using chat.persistence.repository;
using chat.persistence.repository.mock;
using chat.persistence;
using chat.services;
using chat.network.client;
using ServerTemplate;
using protobuf;
namespace chat
{
    using server;
    class StartServer
    {
        static void Main(string[] args)
        {
            
            IUserRepository userRepo = new UserRepositoryMock();
            IChatServer server = new ChatServerImpl(userRepo);

            //IChatServer server = new ChatServerImpl();
          //  ProtoChatServer scs = new ProtoChatServer("127.0.0.1", 55555, server);
            ProtoV3ChatServer scs = new ProtoV3ChatServer("127.0.0.1", 55556, server);
            scs.Start();
            Console.WriteLine("Server started ...");
            //Console.WriteLine("Press <enter> to exit...");
            Console.ReadLine();
            
        }
    }

    public class SerialChatServer: ConcurrentServer 
    {
        private IChatServer server;
        private ChatClientWorker worker;
        public SerialChatServer(string host, int port, IChatServer server) : base(host, port)
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
    public class ProtoChatServer : ConcurrentServer
    {
        private IChatServer server;
        private ProtoChatWorker worker;
        public ProtoChatServer(string host, int port, IChatServer server)
            : base(host, port)
        {
            this.server = server;
            Console.WriteLine("ProtoChatServer...");
        }
        protected override Thread createWorker(TcpClient client)
        {
            worker = new ProtoChatWorker(server, client);
            return new Thread(new ThreadStart(worker.run));
        }
    }
    
    public class ProtoV3ChatServer : ConcurrentServer
    {
        private IChatServer server;
        private ProtoV3ChatWorker worker;
        public ProtoV3ChatServer(string host, int port, IChatServer server)
            : base(host, port)
        {
            this.server = server;
            Console.WriteLine("ProtoChatServer...");
        }
        protected override Thread createWorker(TcpClient client)
        {
            worker = new ProtoV3ChatWorker(server, client);
            return new Thread(new ThreadStart(worker.run));
        }
    }
}
