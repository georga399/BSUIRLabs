using Works.Domain.Entities;
using SerializerLib;

var factories = new List<Factory>()
{
    new Factory(){Storage = new Storage(){Name="phones", CountOfDetails=9999, Director="Pushkin"}, 
                Address="Minsk", PostCode = 121212},
    new Factory(){Storage = new Storage(){Name="cabels", CountOfDetails=10000, Director="Ivanov"}, 
                Address="Moscow", PostCode = 232323},
    new Factory(){Storage = new Storage(){Name="adapters", CountOfDetails=5000, Director="Lermontov"}, 
                Address="Pekin", PostCode = 434343},
    new Factory(){Storage = new Storage(){Name="displays", CountOfDetails=1200, Director="Tolstoy"}, 
                Address="Stambul", PostCode = 454545},
    new Factory(){Storage = new Storage(){Name="volumes", CountOfDetails=6000, Director="Checkhov"}, 
                Address="Deli", PostCode = 909090},
    new Factory(){Storage = new Storage(){Name="batteries", CountOfDetails=5500, Director="Pushkin"}, 
                Address="Minsk", PostCode = 656565}
};
var serializer = new Serializer();
serializer.SerializeByLINQ(factories, "data/factorieslinq.xml");
serializer.SerializeXML(factories, "data/factories.xml");
serializer.SerializeJSON(factories, "data/factories.json");


var factoriesJSON = serializer.DeSerializeJSON("data/factories.json");
Console.WriteLine("Checking serializing oblects in JSON...");
var jsonEnum = factoriesJSON.GetEnumerator();
foreach(var f in factories)
{
    jsonEnum.MoveNext();
    if (f.Equals(jsonEnum.Current))
        Console.WriteLine("OK");
    else
        Console.WriteLine("Wrong");
}

var factoriesXML = serializer.DeSerializeXML("data/factories.xml");
Console.WriteLine("Checking serializing oblects in XML...");
var xmlEnum = factoriesXML.GetEnumerator();
foreach(var f in factories)
{
    xmlEnum.MoveNext();
    if (f.Equals(xmlEnum.Current))
        Console.WriteLine("OK");
    else
        Console.WriteLine("Wrong");
}

var factorieslinq = serializer.DeSerializeByLINQ("data/factorieslinq.xml");
Console.WriteLine("Checking serializing oblects wirh LINQ to XML...");
var linqEnum = factorieslinq.GetEnumerator();
foreach(var f in factories)
{
    linqEnum.MoveNext();
    if (f.Equals(linqEnum.Current))
        Console.WriteLine("OK");
    else
        Console.WriteLine("Wrong");
}