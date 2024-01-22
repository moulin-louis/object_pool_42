//
// Created by llr on 10/18/23.
//
#include "../inc/Workshop.hpp"

void Workshop::executeWorkDay() {
  cout << "Workshop: executing Work Day" << endl;
  for (vector<Worker*>::iterator it = this->register_worker.begin(); it != this->register_worker.end(); it++) {
    (*it)->work();
  }
}

void Workshop::register_workshop(Worker* worker) {
  cout << "Workshop: worker trying to register" << endl;
  const vector<Worker*>::iterator it = std::find(this->register_worker.begin(), this->register_worker.end(), worker);
  if (it != this->register_worker.end()) {
    cout << "Worksop: worker already in" << endl;
    return;
  }
  this->register_worker.push_back(worker);
}

void Workshop::leave(const Worker* worker) {
  cout << "Workshop: worker trying to leave workshop" << endl;
  const vector<Worker*>::iterator it = std::find(this->register_worker.begin(), this->register_worker.end(), worker);
  if (it == this->register_worker.end()) {
    cout << "Worksop: worker was not register" << endl;
    return;
  }
  this->register_worker.erase(it);
}
