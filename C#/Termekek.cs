using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lekerdezesek
{
    internal class Termekek
    {
        private List<Termek> lista;

        public Termekek()
        {
            lista = new List<Termek>();
        }

        public void Generalas()
        {
            lista = new List<Termek>
            {
                new Termek(1, "Laptop", 120000, "Elektronika"),
                new Termek(2, "Okostelefon", 80000, "Elektronika"),
                new Termek(3, "Tablet", 60000, "Elektronika"),
                new Termek(4, "TV", 150000, "Elektronika"),
                new Termek(5, "Hűtőszekrény", 180000, "Háztartás"),
                new Termek(6, "Mosógép", 140000, "Háztartás"),
                new Termek(7, "Vasaló", 10000, "Háztartás"),
                new Termek(8, "Kenyérpirító", 7000, "Háztartás"),
                new Termek(9, "Szék", 20000, "Bútor"),
                new Termek(10, "Asztal", 40000, "Bútor"),
                new Termek(11, "Kanapé", 120000, "Bútor"),
                new Termek(12, "Szekrény", 100000, "Bútor"),
                new Termek(13, "Függöny", 8000, "Lakberendezés"),
                new Termek(14, "Lámpa", 12000, "Lakberendezés"),
                new Termek(15, "Ágy", 150000, "Bútor"),
                new Termek(16, "Toll", 500, "Irodaszer"),
                new Termek(17, "Jegyzetfüzet", 1500, "Irodaszer"),
                new Termek(18, "Monitor", 70000, "Elektronika"),
                new Termek(19, "Egér", 5000, "Elektronika"),
                new Termek(20, "Billentyűzet", 8000, "Elektronika"),
                new Termek(21, "Porzsák", 3000, "Háztartás"),
                new Termek(22, "Kávéfőző", 25000, "Háztartás"),
                new Termek(23, "Hátizsák", 15000, "Divat"),
                new Termek(24, "Cipő", 30000, "Divat"),
                new Termek(25, "Óra", 50000, "Divat")
            };
        }

        public void Kiir()
        {
            lista.ForEach(x => Console.WriteLine(x));
        }

        public List<string> TermekNevei()
        {
            return lista.Select(x => x.Nev).ToList();
        }

        public List<(string nev, double ar)> TermekekNeveiEsArai()
        {
            return lista.Select(x => (x.Nev, x.Ar)).ToList();
        }

        public List<Termek> RendezesArSzerintNovekvo()
        {
            return lista.OrderBy(x => x.Ar).ToList();
        }

        public List<(string nev, double ar, string kategoria)> RendezesArSzerintCsokkeno()
        {
            return lista.OrderByDescending(x => x.Ar).Select(x => (x.Nev, x.Ar, x.Kategoria)).ToList();
        }

        public void DictionaryGyakorlas()
        {
            Dictionary<string, int> stat = new Dictionary<string, int>();

            foreach (var item in lista)
            {
                string kulcs = item.Kategoria;
                if (!stat.ContainsKey(kulcs))
                {
                    stat[kulcs] = 0;
                }
                stat[kulcs]++;
            }

            foreach (KeyValuePair<string, int> item in stat)
            {
                Console.WriteLine(item.Key + ": " + item.Value);
            }
        }

        public void ErtekSzerintiKategoriak()
        {
            var eredmeny = lista.GroupBy(x => x.Ar <= 50000 ? "0-50000" : x.Ar <= 100000 ? "50001-100000" : "100001-").ToList();
            foreach (var item in eredmeny)
            {
                Console.WriteLine("\n" + item.Key + ": ");
                foreach (var termek in item)
                {
                    Console.WriteLine(termek);
                }
            }
        }

        public List<Termek> DragaTermekek()
        {
            return lista.Where(x => x.Ar > 100000).ToList();
        }

        public void Alapok()
        {
            var osszertek = lista.Sum(x => x.Ar);
            osszertek = lista.Where(x => x.Kategoria.Equals("Divat")).Sum(x => x.Ar);
            var atlagar = lista.Where(x => x.Kategoria.Equals("Elektronika")).Average(x => x.Ar);
            var paros = lista.Where(x => x.Azonosito % 2 == 0).ToList();
            var eredmeny = lista.Where(x => x.Ar > 100000).OrderByDescending(x => x.Ar).Select(x => new { x.Nev, x.Ar }).ToList();
            foreach (var item in eredmeny)
            {
                Console.WriteLine(item);
            }
        }

        public void CsoportositasKategoriaSzerint()
        {
            var csoportok = lista.GroupBy(x => x.Kategoria).ToList();
            foreach (var csoport in csoportok)
            {
                Console.WriteLine("\n" + csoport.Key + ": ");
                foreach (var termek in csoport)
                {
                    Console.WriteLine("\t" + termek);
                }
            }
        }

        public List<(string nev, string kategoria)> LegdragabbKategoriankent()
        {
            var eredmeny = lista.GroupBy(x => x.Kategoria)
                                .Select(g => (g.OrderByDescending(x => x.Ar).First().Nev, g.Key))
                                .ToList();
            return eredmeny;
        }
    }
}