#ifndef __queue__
#define __queue__
#include "common.hpp"

#define EMPTY_QUEUE -1
/*
 * El año pasado implementamos la cola de modo que teníamos dos punteros, front y rear. Front apuntaba al primer elemento
 * de la cola, y rear al último. Si metíamos un elemento en la cola lo poníamos en rear y aumentábamos a rear. Si sacábamos
 * un elemento de la cola, sacábamos el que apuntaba front y aumentábamos front. Para hacer esto necesitamos que el
 * el vector pueda aumentar dinámicamente, pero si hacemos esto, al empezar a sacar y meter datos de la cola, nos empezamos a quedar
 * con montón de espacio vacío al principio de la cola, y esta implementación la hace poco eficiente. La implementación del año
 * pasado fue utilizar un vector circular, pero esto implica tener un tamaño bien definido para el vector, ya que si tenemos mitad de los
 * datos al principio y mitad de los datos al final (creo, o al menos es difícil) que no se puede ampliar dinámicamente el vector. Y yo quería
 * implementar una cola que pueda aumentar dinámicamente, así que le he implementado así:
 *
 * Al hacer emplace, si sobra espacio en el vector se coloca normalmente, si está lleno se aumenta el vector y se coloca el elemento al final.
 * Al hacer pop, se guarda temporalmente el primer elemento (al que debería apuntar front), se rueda todo el vector y se devuelve el elemento temporal.
 * 
 * No se si será una buena implementación, pero me pareció adecuada para hacer que pudiese aumentar dinámicamente.
 * Perdón por el tocho de texto pero tenía que aclarar esto :)
 */
class queue_t{
private:
	TDATO* Q_;
	int rear_;
	unsigned int size_;
private:
	void build(void);
	void destroy(void);
	void resize(unsigned int size);
	unsigned int min(unsigned int first, unsigned int second) const;
	void ifemptybuild(void);
public:
	queue_t(void);
	queue_t(unsigned int size);
	~queue_t(void);

	void push(TDATO it);
	TDATO pop(void);
	TDATO& front(void) const;
	TDATO& rear(void) const;
	void emplace(TDATO it);

	unsigned int size(void) const;

	bool empty(void) const;
	bool full(void) const;

	void swap(queue_t& it);

	friend std::ostream& operator<<(std::ostream& os, queue_t& it);
};

#endif