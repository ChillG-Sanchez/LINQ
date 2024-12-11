namespace Lekerdezesek
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Termekek t = new Termekek();
            t.Generalas();
            t.Kiir();
            t.TermekNevei().ForEach(x => Console.WriteLine(x));
            t.TermekekNeveiEsArai().ForEach(x => Console.WriteLine(x.nev + ": " + x.ar));
            t.RendezesArSzerintNovekvo().ForEach(x => Console.WriteLine(x.Nev + ": " + x.Ar + " (" + x.Kategoria + ")"));
            t.RendezesArSzerintCsokkeno().ForEach(x => Console.WriteLine(x.nev + ": " + x.ar + " (" + x.kategoria + ")"));
            t.DictionaryGyakorlas(); // Itt nem hívunk ForEach-et
            t.DragaTermekek().ForEach(x => Console.WriteLine(x));
            t.CsoportositasKategoriaSzerint();
            System.Console.WriteLine("Legdrágább kategóriánként:");
            t.LegdragabbKategoriankent().ForEach(x => Console.WriteLine(x.nev + " (" + x.kategoria + ")"));
        }
    }
}