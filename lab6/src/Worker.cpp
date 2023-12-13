#include "Worker.h"
#include <fstream>
#include <iostream>
Worker::Worker() {
}

Worker::Worker(const Worker & worker) {
    m_sName         = worker.m_sName;
    m_sJobTitle     = worker.m_sJobTitle;
    m_nEntryYear    = worker.m_nEntryYear;
}

Worker::Worker(const std::string &sName) {
    m_sName = sName;
}

Worker::~Worker() {
}

void Worker::Print() const { 
    std::cout << "Worker:"              << std::endl;
    std::cout << m_sName << ", ";
    std::cout << m_sJobTitle << ", "    << std::endl;
    std::cout << m_nEntryYear           << std::endl;
}

void Worker::SetJobTitle(const std::string &sJobTitle) {
    m_sJobTitle = sJobTitle;
}

void Worker::SetName(const std::string &sName) {
    m_sName = sName;
}

void Worker::SetEntryYear(int nEntryYear) {
    m_nEntryYear = nEntryYear;
}

std::string Worker::GetJobTitle() const {
    return m_sJobTitle;
}

std::string Worker::GetName() const {
    return m_sName;
}

int Worker::GetEntryYear() const {
    return m_nEntryYear;
}

void Worker::Save(std::ostream& os) const {
    os << "name: " << m_sName << "\n";
    os << "job_title: " << m_sJobTitle << "\n";
    os << "ey: " << m_nEntryYear << "\n";
    os << "end\n";
    std::cout << "Worker saved successfully.\n";
}

bool Worker::Load(std::istream& is) {
    bool bLoaded = false;
    while (!is.eof()) {
        std::string key, value;
        is >> key;
        if(key == "end")
            break;
        bLoaded |= true;
        is >> value;
        if (key == "name:") {
            m_sName = value;
        }
        else if (key == "job_title:") {
            m_sJobTitle = value;
        }
        else if (key == "ye:") {
            m_nEntryYear = std::stoi(value);
        }
    }
    if(bLoaded)
        std::cout << "Worker loaded successfully.\n";
    return bLoaded;
}



bool Worker::operator<(Worker& worker) const{
    return m_sName < worker.m_sName;
}
bool Worker::operator>(Worker& worker) const{
    return m_sName > worker.m_sName;
}

std::ostream& operator << (std::ostream& os, const Worker& w){
    os << w.m_sName << " " << w.m_sJobTitle << " " << w.m_nEntryYear << std::endl;
}

std::istream& operator >> (std::istream& is, Worker& w){
    std::cout << "enter name: ";
    is >> w.m_sName;
    std::cout << "enter job title: ";
    is >> w.m_sJobTitle;
    std::cout << "enter entry year: ";
    is >> w.m_nEntryYear;
}