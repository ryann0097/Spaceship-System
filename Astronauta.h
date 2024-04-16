#ifndef ASTRONAUTA_HPP_
#define ASTRONAUTA_HPP_

#include <vector>
#include <iostream>

class Astronauta
{
private:

    std::string nomeDoAstronauta;
    std::string cpfDoAstronauta;
    short idadeDoAstronauta;
    bool astronautaEstaVivo = true;
    bool disponibilidadeAstronauta = false;
    std::vector<short>voosDoAstronauta;

public:

    Astronauta(){}
    Astronauta(std::string novoNome, std::string novoCPF, short novaIdade) : nomeDoAstronauta(novoNome), cpfDoAstronauta(novoCPF), idadeDoAstronauta(novaIdade){};

    /** @fn Getters 'n Setters: Disponibilidade do astronauta para voo.
     * 
     * @brief toggleAstronautaDisp: altera o estado do atributo referente à disponibilidade do objeto em questão,
     *        trocando seu estado durante a chamada da função.
     *
     * @brief getAstroanutaDisp: retorna o estado do atributo referente à disponibilidade do objeto em questão,
     *        retornando seu estado durante a chamada da função.
    */

    void toggleAstronautaDisp(){this->disponibilidadeAstronauta = !this->disponibilidadeAstronauta;}
    bool getAstroanutaDisp(){return this->disponibilidadeAstronauta;}

    void toggleAstronautaVida(){this->astronautaEstaVivo = !this->astronautaEstaVivo;}
    bool getAstronautaVida(){return this->astronautaEstaVivo;}

    /** @fn In-class vector manipulation: Voos do astronauta.
     * 
     * @brief
     * 
    */

   void fazerRegistroDeVoo(std::string novoVoo){this->voosDoAstronauta.push_back(novoVoo);}
   void cancelarUltimoRegistro(){this->voosDoAstronauta.pop_back();}

   std::string getCpfDoAstronauta(){return this->cpfDoAstronauta;}
   std::string getNomeDoAstronauta(){return this->nomeDoAstronauta;}

    ~Astronauta();

};


#endif

