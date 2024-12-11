using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lekerdezesek
{
	internal class Termek
	{
		private int azonosito;
		private string nev;
		private double ar;
		private string kategoria;

		public Termek(int azonosito, string nev, double ar, string kategoria)
		{
			this.azonosito = azonosito;
			this.nev = nev;
			this.ar = ar;
			this.kategoria = kategoria;
		}

		public int Azonosito { get => azonosito; set => azonosito = value; }
		public string Nev { get => nev; set => nev = value; }
		public double Ar { get => ar; set => ar = value; }
		public string Kategoria { get => kategoria; set => kategoria = value; }

		public override string ToString()
		{
			return $"{this.azonosito}, {this.nev}, {this.ar}, {this.kategoria}";
		}

        
	}
}