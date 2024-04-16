#ifndef FUNCTIONS_HPP_
#define FUNCTIONS_HPP_

#include "Astronauta.h"
#include "Voo.h"
#include <vector>

Astronauta CadastrarAstronauta(std::vector<Astronauta>astronautasLista){

    std::string nomeParaCadastro;
    std::string cpfParaCadastro;
    short idadeParaCadastro;

    bool nomeValido = false, cpfValido = false, idadeValida = false;

    do{

        std::cout << "\n[Cadastro]: Digite o nome do astronauta para cadastro:\n";
        std::getline(std::cin, nomeParaCadastro);

        if(nomeParaCadastro.empty()){
            std::cout << "[ERRO]: Voce realmente tentou digitar algo?\nPor favor, tente novamente.\n";
            nomeValido = false;
        }
        else{
            for(const auto &astronauta : astronautasLista){
                if(nomeParaCadastro == astronauta.getNomeDoAstronauta){
                    std::cout << "[ERRO]: O nome inserido ja existe na lista de astronautas.\nTente novamente.\n";
                    nomeValido = false;
                    break;
                }
            }   
        }

    } while (!nomeValido);

    do {

        std::cout << "\n[Cadastro]: Digite o CPF do astronauta para cadastro:\n";
        std::getline(std::cin, cpfParaCadastro);

        if(cpfParaCadastro.empty()){std::cout << "\n[ERRO]: Voce realmente tentou digitar algo?\nPor favor, tente novamente.\n";}
        else{
            for(const auto &astronauta : astronautasLista){
                if(cpfParaCadastro == astronauta.getCpfDoAstronauta){
                    std::cout << "[ERRO]: O CPF inserido ja existe na lista de astronautas.\nTente novamente.\n";
                    cpfValido = false;
                    break;
                }
            }
        }

    } while (!cpfValido);

    do{

        std::cout << "\n[Cadastro]: Digite a idade do astronauta para cadastro:\n";
        std::cin >> idadeParaCadastro;

        if(idadeParaCadastro < 18){std::cout << "\n[ERRO]: Idade abaixo do limite permitido para NASA.\n";} 
        else if(idadeParaCadastro > 90){std::cout << "\n[ERRO]: Idade acima do limite permitido para NASA.\n";}
        else{idadeValida = true;}

    } while (!idadeValida);

    return Astronauta(nomeParaCadastro, cpfParaCadastro, idadeParaCadastro);

}

Voo CadastrarVoo(std::vector<Voo>voosLista){

    short codigoDeVooParaCadastro;
    bool codigoValido = false;

    do{

    } while (!codigoValido);

}




#endif