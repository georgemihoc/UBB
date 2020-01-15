namespace Lab10.Repository
{
    class JucatorActivInFileRepository : InFileRepository<string, JucatorActiv>
    {

        public JucatorActivInFileRepository( string fileName) : base(null,fileName, EntityToFileMapping.CreateJucatorActiv)
        {
            
        }

    }

}