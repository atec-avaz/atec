using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Aula02
{
    public class Pessoa
    {
        private int idade;
        private string nome;
        private DateTime dtNasc;

        public Pessoa()
        {
            idade = 0;
            nome = "John Doe";
        }

        public Pessoa(DateTime dataNascimento): this()
        {
            this.dtNasc = dataNascimento;
            idade = calculateIdade(DateTime.Now);
        }


        /// <summary>
        /// Este metodo permite coisas fantasticas
        /// </summary>
        /// <param name="nome">Nome brutal</param>
        /// <exception cref="ArgumentNullException"></exception>
        public void setNome(string nome)
        {
            if (nome == null) 
                throw new ArgumentNullException("nome", 
                    "O Nome não pode ser vazio");
            this.nome = nome;
        }

        public string getNome()
        {
            return nome;
        }

        public int getIdade()
        {
            return idade;
        }

        public int getAnoNascimento()
        {
            return dtNasc.Year;
        }

        private int calculateIdade(DateTime dataBase)
        {
            int age = dataBase.Year - dtNasc.Year;
            if (dataBase < dtNasc.AddYears(age)) age--;

            return age;
        }

        public int Idade
        {
            get
            {
                return idade;                
            }            
        }

        public string Nome
        {
            get { return nome; }
            set
            {
                if (value == null)
                    throw new ArgumentNullException("nome", "Introduza um nome válido");

                nome = value;
            }
        }

        public DateTime DataNascimento
        {
            get { return dtNasc; }
            set { 
                dtNasc = value;
                idade = calculateIdade(DateTime.Now);
            }
        }

    }
}
