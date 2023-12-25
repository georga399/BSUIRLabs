using Works.Domain.Interfaces;
using Works.Domain.Entities;
using System.Xml.Linq;
using System.Runtime.CompilerServices;
using System.Xml.Serialization;
using System.Text.Json;
namespace SerializerLib;
public class Serializer: ISerializer
{
    public IEnumerable<Factory> DeSerializeByLINQ(string fileName)
    {
        var xdoc = XDocument.Load(fileName);
        var xel = xdoc.Element("ArrayOfFactory");
        foreach(var f in xel!.Elements("factory"))
        {
            var postCode = f.Attribute("postCode");
            var address = f.Element("address");
            var xstorage = f.Element("storage");
            var stname = xstorage?.Attribute("name");
            var stdir = xstorage?.Element("director");
            var stcount = xstorage?.Element("countOfDetails");
            yield return new Factory(){
                Storage = new Storage(){Director=stdir!.Value, Name=stname!.Value, CountOfDetails= Int32.Parse(stcount!.Value)},
                Address = address!.Value,
                PostCode = Int32.Parse(postCode!.Value)}!;
        }
        yield break;
    }
    public IEnumerable<Factory> DeSerializeXML(string fileName)
    {
        var xmlSerializer = new XmlSerializer(typeof(List<Factory>));
        // var xmlSerializer = new XmlSerializer(typeof(ArrayOf));
        using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
        {
            var factories = xmlSerializer.Deserialize(fs) as IEnumerable<Factory>;
            return factories!;
        }
    }
    public IEnumerable<Factory> DeSerializeJSON(string fileName)
    {
        using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
        {
            var factories = JsonSerializer.Deserialize<IEnumerable<Factory>>(fs);
            return factories!;
        }
    }
    public void SerializeByLINQ(IEnumerable<Factory> factories, string fileName)
    {
        var xdoc = new XDocument();
        var xel = new XElement("ArrayOfFactory");
        foreach(var f in factories)
        {
            var xfact = new XElement("factory");
            xfact.Add(new XAttribute("postCode", f.PostCode));
            xfact.Add(new XElement("address", f.Address));
            xfact.Add(new XElement("storage", 
                new XAttribute("name", f.Storage!.Name),
                new XElement("director", f.Storage.Director),
                new XElement("countOfDetails", f.Storage.CountOfDetails)));
            xel.Add(xfact);
        }
        xdoc.Add(xel);
        xdoc.Save(fileName);
    }
    public void SerializeXML(IEnumerable<Factory> factories, string fileName)
    {
        var xmlSerializer = new XmlSerializer(factories.GetType());
        using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
        {
            xmlSerializer.Serialize(fs, factories);
        }
    }
    public void SerializeJSON(IEnumerable<Factory> factories, string fileName)
    {
        using (FileStream fs = new FileStream(fileName, FileMode.OpenOrCreate))
        {
            JsonSerializer.Serialize<IEnumerable<Factory>>(fs, factories);
        }
    }
}
