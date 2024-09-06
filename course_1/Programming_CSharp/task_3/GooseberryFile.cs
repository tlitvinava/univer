using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace task_3
{
        public class Number

        {
            public int ProcessNumber(int number)
            {
                if (number % 2 == 0)
                {
                    return number / 2;
                }
                else
                {
                    return number + 3;
                }
            }
        }
}
