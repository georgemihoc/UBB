using System;
using System.Net.Sockets;

using System.Threading;
using swim.services;
// using swim.networking;
using ServerTemplate;
using swim.networking;
using swim.persistence;
namespace swim.server
{
    public class StartServer
    {
        //static SwimServerImpl serviceTest;
        static void Main(string[] args)
        {
            ParticipantDbRepository participantDbRepository = new ParticipantDbRepository();
            ProbaDbRepository probaDbRepository = new ProbaDbRepository();
            InscriereDbRepository inscriereDbRepository = new InscriereDbRepository();
            OrganizatorDbRepository organizatorDbRepository = new OrganizatorDbRepository();

            //serviceTest = new SwimServerImpl(participantDbRepository, probaDbRepository, inscriereDbRepository, organizatorDbRepository);
            IServices serviceImpl = new SwimServerImpl(participantDbRepository, probaDbRepository, inscriereDbRepository, organizatorDbRepository); ;
            //IServices serviceImpl = getService();


			SerialSwimServer server = new SerialSwimServer("127.0.0.1", 55556, serviceImpl);
            server.Start();
            Console.WriteLine("Server started ...");
            //Console.WriteLine("Press <enter> to exit...");
            Console.ReadLine();
            
        }
       
    }

    public class SerialSwimServer: ConcurrentServer 
    {
        private IServices server;
        private ChatClientWorker worker;
        public SerialSwimServer(string host, int port, IServices server) : base(host, port)
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
