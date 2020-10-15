/*test del programma*/
/*paradigma di sviluppo --> prima scrivo il test e poi scrivo la roba che il test chiama*/
/*sistem subvertioning --> GIT*/
/*tutorial su come si usa git*/
/*#include "includes/Address.hpp" --> metto le librerie in una sottocaretlla del progetto*/
#include "iAddress.hpp"

#define A_RANDOM_PORT 5

int main(int argc, char const *argv[])
{
	/*creo un  indirizzo e passo IP e Port*/
	Address a(IP_LO, A_RANDOM_PORT);
	if(A_RANDOM_PORT != a.getPort()) /*Mandalorian stuff!*/
		return -1;
	if(cmpStr(a.getIp(), IP_LO) != 0) /*HARD CODING uso delle costanti nel codice, dichiaro define ...*/
		return -2;

	/*costruttore per copia*/
	Address b(a);
		if(a.getPort() != b.getPort()) 
		return -3;
	if(cmpStr(a.getIp(), b.getIp()) != 0) 
		return -4;

	/*testare altri due costruttori, metodi set struttura e get struttura e metodo toString()*/

	return 0;
}

/*attenzione ai memory leak --> solo su programmi server, su programmi test può anche essere ridotta, tanto quando il programma si chiude si libera la memoria.
								posso scrivere codice schifoso nei test*/