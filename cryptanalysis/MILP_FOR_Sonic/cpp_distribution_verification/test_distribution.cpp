#include "/opt/gurobi1103/linux64/include/gurobi_c++.h"
#include <cmath>

using namespace std;

int main(int argc,char *argv[]){

GRBEnv env = GRBEnv(true);
env.set("LogFile","mip1.log");
env.start();

GRBModel P = GRBModel(env,argv[1]);

P.set(GRB_IntParam_PoolSearchMode,2);
P.set(GRB_IntParam_PoolSolutions,10000);
P.set(GRB_DBL_PAR_POOLGAP,"10");

P.optimize();

int nSolution = P.get(GRB_IntAttr_SolCount);
cout << "Number of solution found:" << nSolution <<endl;

int distribution[100] = {};

for(int e = 0;e<nSolution;e++){
    P.set(GRB_IntParam_SolutionNumber,e);
    distribution[int(round(P.get(GRB_DoubleAttr_PoolObjVal)))]++;
    //cout << round(P.get(GRB_DoubleAttr_PoolObjVal)) << " ";

}

for(int i=0;i<100;i++){
    if(distribution[i]!=0){
        cout << i << " : " << distribution[i] << " \n";
    }

}

return 0;
}


