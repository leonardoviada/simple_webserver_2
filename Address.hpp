#ifndef __ADDRESS_HPP
#define __ADDRESS_HPP

#include <arpa/inet.h>
#include <sys/socket.h>

#define IP_LO "127.0.0.1"
#define IP_DHCP "0.0.0.0"

/*class Address : public class --> ereditarietà*/
class Address {

	/*in c++ si scrive la classe, si indicano i prototipi e fuori dalla classe si fa l'implementazione(call e ret)
	oppure dichiaro i metodi e poi gli implemento in class (uguale come fare una funzione inline --> il compilatore non crea una call, ma copia e incolla il codice) --> tempi di risposta veloci*/

/*attributo della calsse*/
private: struct sockaddr_in * address;

/*sono prototipi*/
public: Address(char*, int);
		Address(struct sockaddr_in*);
		Address();
		/*costruttore di copia in c++*/
		/*quando c'è const in un parametro di una funzione vuol dire che il valore che viene ricevuto non può essere modificato all'interno del metodo
		(è un indirizzo di qualcosa, non posso modificarlo. &--> per indicare che quel valore non può essere modificato)*/
		Address(const Address&);

		~Address();

		Address* setIp(char*);
		Address* setPort(int);
		Address* setAddress(struct sockaddr_in*);

		char* getIp();
		int getPort();
		struct sockaddr_in* getAddress();

		char* toString();

};

Address* Address::setIp(char* ip) {
	inet_aton(ip, &address->sin_addr)
}

/*implemeto main e metodi interni tranne il costruttore di copia*/
#endif // __ADDRESS_HPP