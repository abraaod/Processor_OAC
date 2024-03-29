#ifndef _MEMORY_
#define _MEMORY_
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include "Tokenizer.hpp"
/**
 * Memory class, here is held a vector with all registers
*/
class Memory
{

  private:
    std::vector<std::string> registers;
  public:

    Memory(){
        
       l_registers();
    }

    /**
     * @return a vector containing the values of registers
    */
    std::vector<std::string> getRegisters(){
        return registers;
    }
    
    void teste(){
        std::cout << "rodou teste" << std::endl;
    }

    /**
     * Função pra atualizar valor de um registrador
     * @param dest endereço do registrador
     * @param result valor a ser adicionado
    */
    void att_registers(int dest, int result){
        registers[dest] = std::to_string(result);
    }

    /**
     * Prints all the values of the registers
    */
    void print(){
        for(auto i = registers.begin(); i != registers.end(); i++){
            cout << *i << " ";
        }
        cout << endl;
    }
    /**
     * Função pra ler todos os valores dos registradores, a partir de um arquivo
    */
    void l_registers()
    {
        std::ifstream arquivo("files/regs.txt", std::fstream::in);
        std::string line;
        while (std::getline(arquivo, line))
        {
            if (!line.empty())
            {
                Tokenizer tokenizer(line);
                std::vector<std::string> token = tokenizer.getToken();
                for (auto i(0u); i < token.size(); i++)
                {
                    registers.push_back(token.at(i));
                }
            }
        }
        arquivo.close();
    }
};
#endif