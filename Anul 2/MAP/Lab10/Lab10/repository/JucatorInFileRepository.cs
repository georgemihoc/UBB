
namespace Lab10.Repository
{
    class JucatorInFileRepository : InFileRepository<string, Jucator>
    {

        public JucatorInFileRepository( string fileName) : base(null,fileName, EntityToFileMapping.CreateJucator)
        {
            
        }

    }

}