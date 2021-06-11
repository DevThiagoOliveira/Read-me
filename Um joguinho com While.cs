using System;


namespace CursoCSharp.EstruturaDeControle
{
    class EstruturaWhile
    {
        public static void Executar()
        {
            Random random = new Random();

            int numeroSecreto = random.Next(1, 16);

            bool numeroEncontrado = false;
            int tentativasRestantes = 5;
            int tentativas = 0;

            while (tentativasRestantes > 0 && !numeroEncontrado)
            {
                Console.Write("Informe o número : ");
                int.TryParse(Console.ReadLine(), out int numero);

                tentativas++;
                tentativasRestantes--;

                if (numeroSecreto == numero)
                {
                    numeroEncontrado = true;
                    var corAnteriorConsole = Console.BackgroundColor;
                    Console.BackgroundColor = ConsoleColor.Green;
                    Console.ForegroundColor = ConsoleColor.Black;

                    Console.WriteLine("Parabens!!\n\n Você acertou o numero {0}.\n tentativas {1} ",numero,tentativas);

                    Console.BackgroundColor = corAnteriorConsole;
                    Console.ForegroundColor = corAnteriorConsole;
                }else if (numero > numeroSecreto)
                {
                    Console.WriteLine("Você passou do número, tente um número menor");
                    Console.WriteLine("Você tem {0}, tentativas restantes.",tentativasRestantes);
                }else if (numero < numeroSecreto)
                {
                    Console.WriteLine("Número menor, tente um número maior");
                    Console.WriteLine("Voce tem {0}, tentativas restantes",tentativasRestantes);
                }else if (tentativasRestantes == 0)
                {
                    Console.WriteLine("Que pena, você não acertou o número.");
                }
            }

        }
    }
}
