"""
Applying the monomial prediction technique to find integral
distinguishers of WARP in the single-key setting
Copyright (C) Jan 2, 2022 Hosein Hadipour

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
"""

import os
import time
import pickle
from itertools import combinations
from math import factorial
from math import log2
from typing import final
from pysat import solvers
from pysat import formula
from argparse import ArgumentParser, RawTextHelpFormatter
# from pysat import pb
# import datetime



class Sonic:
    count = 0
    def __init__(self, nrounds=10, solver_name="cadical153", word_size=4, branches=32):
        Sonic.count += 1
        self.nrounds = nrounds
        self.sat_solver_name = solver_name
        self.supported_sat_solvers = list(solvers.SolverNames.cadical153) + \
             list(solvers.SolverNames.cadical103) + \
               list(solvers.SolverNames.glucose4) + \
                   list(solvers.SolverNames.glucose3) + \
                       list(solvers.SolverNames.lingeling) + \
                           list(solvers.SolverNames.maplesat) + \
                           list(solvers.SolverNames.maplechrono) + \
                               list(solvers.SolverNames.maplecm) + \
                                   list(solvers.SolverNames.minicard) + \
                                       list(solvers.SolverNames.minisat22) + \
                                           list(solvers.SolverNames.minisatgh)
        assert(self.sat_solver_name in self.supported_sat_solvers)
        if self.sat_solver_name in solvers.SolverNames.cadical153:
            self.sat_solver = solvers.Cadical153()
        elif self.sat_solver_name in solvers.SolverNames.cadical103:
            self.sat_solver = solvers.Cadical103()
        elif self.sat_solver_name in solvers.SolverNames.glucose4:
            self.sat_solver = solvers.Glucose4()
        elif self.sat_solver_name in solvers.SolverNames.glucose3:
            self.sat_solver = solvers.Glucose3()
        elif self.sat_solver_name in solvers.SolverNames.lingeling:
            self.sat_solver = solvers.Lingeling()
        elif self.sat_solver_name in solvers.SolverNames.maplesat:
            self.sat_solver = solvers.Maplesat()
        elif self.sat_solver_name in solvers.SolverNames.maplechrono:
            self.sat_solver = solvers.MapleChrono()
        elif self.sat_solver_name in solvers.SolverNames.maplecm:
            self.sat_solver = solvers.MapleCM()
        elif self.sat_solver_name in solvers.SolverNames.minicard:
            self.sat_solver = solvers.Minicard()
        elif self.sat_solver_name in solvers.SolverNames.minisat22:
            self.sat_solver = solvers.Minisat22()
        elif self.sat_solver_name in solvers.SolverNames.minisatgh:
            self.sat_solver = solvers.MinisatGH()

        self.cnf_formula = formula.CNF()
        self.solver = self.solver = solvers.Solver(name=self.sat_solver_name)
        self.variables_dictionary = dict()
        self.top_variable_identifier_so_far = 0
        self.cnf_file_name = f"sonic_{branches*word_size}_nr_{self.nrounds}.cnf"
        self.result_file_name = f"result_{branches*word_size}_nr_{self.nrounds}.txt"
        self.word_size = word_size
        self.branches = branches
        self.permute_words = [1, 0]
        # and inputs: 1, 2
        # and output: 3
        self.and_cnf_template = [[3, -1], [3, -2], [-3, 1], [-3, 2]]
        
        # xor inputs: 1, 2
        # xor output: 3
        self.xor_cnf_template = [[-1, -2], [-2, 3], [-1, 3], [1, 2, -3]]

        # xor3 inputs: 1, 2, 3
        # xor3 output: 4
        self.xor3_cnf_template = [[-2, -3], [-1, -3], [-1, -2], [-3, 4], [-2, 4], [-1, 4], [1, 2, 3, -4]]
        self.xor3_with_constant_cnf_template = [[-2, -3], [-1, -3], [-1, -2], [-3, 4], [-2, 4], [-1, 4]]
    

    def update_variables_dictionary(self, new_vars):
        """
        This method is used to update variables' dictionary
        """
        for nv in new_vars:
            if nv not in self.variables_dictionary.keys():
                self.top_variable_identifier_so_far += 1
                self.variables_dictionary[nv] = self.top_variable_identifier_so_far

    @staticmethod
    def flatten_state(s):
        state_bits = [s[i][j] for i in range(len(s)) for j in range(len(s[0]))]
        return state_bits

    def inv_permute_words(self, state):
        temp = [0]*self.branches
        for i in range(self.branches):
            temp[i] = state[self.permute_words[i]]
        return temp

    def rot_left_word(self, state, val):
        temp = [0]*self.word_size
        for i in range(self.word_size):
            temp[(i+val)%self.word_size] = state[i]
        return temp
    
    def permute_word(self, state, val):
        temp = [0]*self.word_size
        for i in range(self.word_size):
            temp[(i*val)%self.word_size] = state[i]
        return temp
        
    
    def generate_round_x_variables(self, rn):
        """
        Generate the input variables of rn'th round
        """

        x = [[f"x_{rn}_{word}_{bit}" for bit in range(self.word_size)] for word in range(self.branches)]
        self.update_variables_dictionary(self.flatten_state(x))
        return x
    
    def generate_round_y_z_k_variables(self, rn):
        """
        Generate the intermediate variables in rn'th round
        """

        y = [[f"y_{rn}_{word}_{bit}" for bit in range(self.word_size)] for word in range((self.branches//2)*11)]
        z = [[f"z_{rn}_{word}_{bit}" for bit in range(self.word_size)] for word in range(self.branches//2)]
        k = [[f"k_{rn}_{word}, {bit}" for bit in range(self.word_size)] for word in range(self.branches//2)]
        self.update_variables_dictionary(self.flatten_state(y))
        self.update_variables_dictionary(self.flatten_state(z))
        self.update_variables_dictionary(self.flatten_state(k))
        return y, z, k
        
    def constraints_by_fork(self, a, b1, b2):
        """
        a ---fork---> (b1, b2)
        """

        self.cnf_formula.append([-self.variables_dictionary[a],\
                                self.variables_dictionary[b1],\
                                self.variables_dictionary[b2]])
        self.cnf_formula.append([-self.variables_dictionary[b1], self.variables_dictionary[a]])
        self.cnf_formula.append([-self.variables_dictionary[b2], self.variables_dictionary[a]])
    
    def word_fork(self, s, s1, s2):
        constraints = ""
        for bit in range(self.word_size):
            self.constraints_by_fork(s[bit], s1[bit], s2[bit])
        return constraints

    def constraints_by_xor(self, a1, a2, b):
        """
        a1, a2 ---> b = a1 + a2
        """
        substitution_list = [self.variables_dictionary[x] for x in  [a1, a2, b]]
        for sl in self.xor_cnf_template:
            temp = []
            for index in sl:
                if index > 0:
                    temp.append(substitution_list[index - 1])
                else:
                    temp.append(-substitution_list[abs(index) - 1])
            self.cnf_formula.append(temp)
    
    def word_xor(self, s1, s2, s):
        for bit in range(self.word_size):
            self.constraints_by_xor(s1[bit], s2[bit], s[bit])
            
    def constraints_by_and(self, a1, a2, b):
        """
        a1, a2 ---> b = a1 * a2
        """
        substitution_list = [self.variables_dictionary[x] for x in  [a1, a2, b]]
        for sl in self.and_cnf_template:
            temp = []
            for index in sl:
                if index > 0:
                    temp.append(substitution_list[index - 1])
                else:
                    temp.append(-substitution_list[abs(index) - 1])
            self.cnf_formula.append(temp)
    
    def word_and(self, s1, s2, s):
        for bit in range(self.word_size):
            self.constraints_by_and(s1[bit], s2[bit], s[bit])
    
    def constraints_by_3xor(self, a1, a2, a3, b, constant=0):
        """
        a1, a2, a3 ---> b = a1 + a2 + a3
        or
        a1, a2, a3 ---> b = a1 + a2 + a3 + 1
        """
        
        assert(constant in [0, 1])
        substitution_list = [self.variables_dictionary[x] for x in  [a1, a2, a3, b]]        
        if constant == 0:
            template = self.xor3_cnf_template
        elif constant == 1:
            template = self.xor3_with_constant_cnf_template        
        for sl in template:
            temp = []
            for index in sl:
                if index > 0:
                    temp.append(substitution_list[index - 1])
                else:
                    temp.append(-substitution_list[abs(index) - 1])
            self.cnf_formula.append(temp)
    
    def word_3xor(self, s1, s2, s3, s, constant=0):
        for bit in range(self.word_size):
            constant_bit = (constant >> (self.word_size - 1 - bit)) & 0x1
            self.constraints_by_3xor(s1[bit], s2[bit], s3[bit], s[bit], constant_bit)
    
    def generate_constraints(self):
        """
        Generate the constraints of MILP model
        """

        for rn in range(self.nrounds):
            x_in = self.generate_round_x_variables(rn)
            y, z, k = self.generate_round_y_z_k_variables(rn)
            x_out = self.generate_round_x_variables(rn + 1)
            x_middle = self.inv_permute_words(x_out)
            for word in range(self.branches//2):
                if rn == 0:
                  self.word_fork(x_in[2*word], y[5*word], y[5*word+1])
                else:
                  self.word_fork(self.permute_word(x_in[2*word],15), y[5*word], y[5*word+1])
                self.word_fork(y[5*word+1], y[5*word+2], y[5*word+3])
                self.word_fork(y[5*word+3], y[5*word+4], y[5*word+5])
                self.word_fork(y[5*word+5], y[5*word+6], y[5*word+7])
                self.word_fork(y[5*word+7], y[5*word+8], y[5*word+9])
                self.word_3xor(self.rot_left_word(y[5*word+6],1), self.rot_left_word(y[5*word+8],8), self.rot_left_word(y[5*word+9],10), y[5*word+10])
                self.word_xor(y[5*word+10], k[word], x_middle[2*word])
                self.word_and(self.rot_left_word(y[5*word],0),self.rot_left_word(y[5*word+2],1), z[2*word])
                self.word_3xor(z[2*word], self.rot_left_word(y[5*word+4],2), x_in[2*word + 1], x_middle[2*word + 1])
    
    def exclude_key_independent_term(self):
        """
        Limit the key variables to not be all zero
        """

        key_vars = [self.variables_dictionary[var] \
            for var in self.variables_dictionary.keys() if "k" in var]
        self.cnf_formula.append(key_vars)
    
    def generate_sat_model(self):
        self.generate_constraints()
        self.exclude_key_independent_term()
        self.cnf_formula.to_file(self.cnf_file_name)
        self.sat_solver.append_formula(self.cnf_formula)

    def check_cube(self, fixed_indices, target_output_bits):
        # Fix the input choice vector
        input_vars = self.flatten_state(self.generate_round_x_variables(0))
        output_vars = self.flatten_state(self.generate_round_x_variables(self.nrounds))

        input_active_pattern = []
        for i in range(self.branches*self.word_size):
            if i in fixed_indices:
                input_active_pattern.append(-self.variables_dictionary[input_vars[i]])
            else:
                input_active_pattern.append(self.variables_dictionary[input_vars[i]])
        
        balanced_bits = []
        not_checked_bits = []
        start_time = time.time()
        for output_bit in target_output_bits:
            output_active_pattern = []
            for i in range(self.branches*self.word_size):
                if i != output_bit:
                    output_active_pattern.append(-self.variables_dictionary[output_vars[i]])
                else:
                    output_active_pattern.append(self.variables_dictionary[output_vars[i]])
            assumptions = input_active_pattern + output_active_pattern
            ##########################
            ##########################
            result = self.sat_solver.solve(assumptions=assumptions)
            ##########################
            ##########################
            if result == True:
                # print("Output bit number {:03d} may NOT be key-independent :-(".format(output_bit))
                pass
            elif result == False:
                balanced_bits.append(output_bit)
                # print("Output bit number {:03d} is key-independent ;-)".format(output_bit))
            else:
                not_checked_bits.append(output_bit)
                # print("Output bit number {:03d} was not checked!".format(output_bit))
        elapsed_time = time.time() - start_time
        number_of_balanced_bits = len(balanced_bits)
        print(f"Number of key-independent bits: {number_of_balanced_bits}")
        print(f"Key-Independent bits:\n{balanced_bits}")
        print(f"Not-Checked bits:{not_checked_bits}\n")
        print("Time used to solve: {:0.02f}".format(elapsed_time))        
        ######################### Save results in output file ##############################
        with open(self.result_file_name, "a") as outputfile:
            separator_line = "#"*100 + "\n"
            outputfile.write(separator_line)
            outputfile.write(f"Fixed input positions: {fixed_indices}\n")
            outputfile.write(f"Key-independent output positions: {balanced_bits}\n")
            outputfile.write(f"Number of key-independent bits: {number_of_balanced_bits}\n")
        ####################################################################################
        return balanced_bits

def parse_args():
    """
    parse input parameters
    """

    parser = ArgumentParser(description="This tool derives and solves the SAT "
                                        "model corresponding to integral analysis "
                                        "based on monomial prediction",
                            formatter_class=RawTextHelpFormatter)
    parser.add_argument("-nr", "--nrounds", default=21, type=int, help="number of rounds\n")
    parser.add_argument("-sl", "--solver", default="minisat22", type=str,
                        choices=['cadical153', 'cadical103', 'glucose3', 'glucose4', 'lingeling', 'maplechrono', 'maplecm', 'maplesat', 'minicard', 'minisat22', 'minisat-gh'],
                        help="choose a SAT solver\n")
    parser.add_argument("-bl", "--blocksize", default=128, type=int, help="block size\n")
    return vars(parser.parse_args())

if __name__ == '__main__':
    locals().update(parse_args())    
    separator_line = "#"*100 + "\n"
    sonic = Sonic(nrounds=nrounds,
                solver_name=solver, word_size=blocksize//2, branches=2)
    with open(sonic.result_file_name, "w") as outputfile:
        outputfile.write(f"Results of applying monomial prediction method on {sonic.nrounds} rounds of Sonicpermute_{blocksize}\n")
    mp_dict = dict()
    sonic.generate_sat_model()
    if not os.path.exists(f"mpdict_{blocksize}_nr_{sonic.nrounds}.pyobj"):
        start_time = time.time()
        for bit in range(0, blocksize):            
            print(separator_line)
            print(f"Fixed index: {bit}")
            mp_dict[(bit,)] = sonic.check_cube(fixed_indices=[bit], target_output_bits = range(blocksize))
        elapsed_time = time.time() - start_time
        time_line = "Total time to compute monomial prediction dictionary (mpdict): {:0.02f}\n".format(elapsed_time)        
        with open(sonic.result_file_name, "a") as outputfile:
            outputfile.write(time_line)
        print(time_line)
        # Store the results in non-volatile memory for later uses
        with open(f"mpdict_{blocksize}_nr_{sonic.nrounds}.pyobj", "wb") as mp_dict_file:
            pickle.dump(mp_dict, mp_dict_file)
    else:
        with open(f"mpdict_{blocksize}_nr_{sonic.nrounds}.pyobj", "rb") as mp_dict_file:
            mp_dict = pickle.load(mp_dict_file)

    # Reduction of data complexity
    start_time = time.time()
    sufficient_list = [i for i in range(blocksize) if mp_dict[(i,)] != []]
    sf_size = len(sufficient_list)
    constant_part_size = 2
    flag = True
    while flag:
        flag = False
        print(separator_line)
        print(f"Checking constant parts of size {constant_part_size} bits")
        total_possible_cases = factorial(sf_size) // \
                         (factorial(sf_size - constant_part_size) * factorial(constant_part_size))
        total_possible_cases = log2(total_possible_cases)
        print("Worst-case complexity: 2^({:0.02f})".format(total_possible_cases))        
        time.sleep(5)
        for fixed_indices in combinations(sufficient_list, constant_part_size):
            balanced_sets = [set(mp_dict[(i,)]) for i in fixed_indices]
            common_output_bbits = set.intersection(*balanced_sets)
            if common_output_bbits != {}:
                key_independent_bits = sonic.check_cube(fixed_indices=list(fixed_indices), 
                                                        target_output_bits=list(common_output_bbits))
                if key_independent_bits != []:
                    flag = True
                    constant_part_size += 1
                    break
    
    # Find a set of fixed inidces yielding the maximum number of key-independent bits
    best_fixed_positions = (blocksize,)
    mp_dict[(blocksize,)] = []
    constant_part_size -= 1
    key_independent_bits = []
    with open(sonic.result_file_name, "a") as outputfile:
        for fixed_indices in combinations(sufficient_list, constant_part_size):
            balanced_sets = [set(mp_dict[(i,)]) for i in fixed_indices]
            common_output_bbits = set.intersection(*balanced_sets)
            if common_output_bbits != {}:
                key_independent_bits = sonic.check_cube(fixed_indices=list(fixed_indices), 
                                                            target_output_bits=list(common_output_bbits))
                if len(key_independent_bits) >= 1:
                    outputfile.write(separator_line)
                    outputfile.write(f"{fixed_indices} ==> {key_independent_bits}\n")
                if len(key_independent_bits) > len(mp_dict[best_fixed_positions]):
                    best_fixed_positions = fixed_indices
                    mp_dict[best_fixed_positions] = key_independent_bits
    
    elapsed_time = time.time() - start_time
    time_line = "Time used to reduce the data complexity: {:0.02f}\n".format(elapsed_time)
    print(time_line)
    final_result = f"Best fixed input positions: {best_fixed_positions}\n"
    final_result += f"Key-independent output positions: {mp_dict[tuple(best_fixed_positions)]}"
    print(final_result)
    with open(sonic.result_file_name, "a") as output_file:
        output_file.write(separator_line)
        output_file.write(time_line)
        output_file.write(final_result)
