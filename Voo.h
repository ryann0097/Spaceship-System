#ifndef VOO_HPP_
#define VOO_HPP_

#include <iostream>
#include "Astronauta.h"
#include <algorithm>
#include <vector>

typedef enum {planejado, curso, sucesso, insucesso} estadosVoo;

class Voo
{
private:

   short codigoDoVoo;
   estadosVoo estadoDeVoo = planejado;
   std::vector<Astronauta>astronautasEmVoo;

public:

    Voo(short novoCodigo) : codigoDoVoo(novoCodigo){};

    bool adicionarAstronautaEmVoo(std::string cpfDoAstronauta){

        if(this->estadoDeVoo != planejado){
            std::cout << "\n[Erro]: O voo selecionado nao esta disponivel para alteracoes.\n";
            return false;
        }

        for(const auto &astronauta : this->astronautasEmVoo){
            std::string verifDeCpfAtual = astronauta.getNomeDoAstronauta();
            if(cpfDoAstronauta == verifDeCpfAtual && astronauta.getAstroanutaDisp()){
                std::cout << "\n[Alteracao]: O astronauta de CPF " << verifDeCpfAtual << " foi adicionado com sucesso ao voo.\n";
                return true;
            }
        }

        return false;
    }

    bool removerAstronautaEmVoo(std::string cpfDoAstronauta){

        if(this->estadoDeVoo != planejado){
            std::cout << "\n[Erro]: O voo selecionado nao esta disponivel para alteracoes.\n";
            return false;
        }

        for(const auto &astronauta : this->astronautasEmVoo){
            std::string verifDeCpfAtual = astronauta.getCpfDoAstronauta();
            if(cpfDoAstronauta == verifDeCpfAtual && astronauta.getAstronautaDisp()){
                std::cout << "\n[Alteracao]: O astronauta de CPF " << verifDeCpfAtual << " foi removido com sucesso do voo.\n";
                return true;
            }
        }

        return false;
    }
    
    bool lancarVoo(){
        bool todosAstronautasDisponiveis = std::all_of(this->astronautasEmVoo.begin(), this->astronautasEmVoo.end(), );

        if(!todosAstronautasDisponiveis){return false;}

        for(const auto &astronauta : this->astronautasEmVoo){
            astronauta.toggleAstronautaDisp();
            astronauta.voosDoAstronauta.push_back(this->codigoDoVoo);
        }

        this->estadoDeVoo = curso;

        return true;

    } 

    bool explodirVoo(){

        if(this->estadoDeVoo == curso){
            return false;
        }
        for(const auto &astronauta : this->astronautasEmVoo){
            astronauta.toggleAstronautaVida();
        }

        this->estadoDeVoo = insucesso;
    }

    bool finalizarVoo(){
        if(this->estadoDeVoo == curso){
            for(const auto &astronauta : this->astronautasEmVoo){
                astronauta.toggleAstronautaDisp();
            }
        }
        this->estadoDeVoo = sucesso;
    }

    ~Voo();
};

#endif