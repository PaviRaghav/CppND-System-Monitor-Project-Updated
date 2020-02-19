#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"
#include "processor.h"
#include "system.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// TODO: Return the system's CPU
Processor& System::Cpu() { return cpu_; }

void System::refreshProcesses() {
    processes_.clear();
    vector<int> pids = LinuxParser::Pids();
    for (uint i=0; i<pids.size(); i++) {
        Process proc;
        proc.Pid(pids[i]);
        int uid = LinuxParser::Uid(pids[i]);
        proc.User(LinuxParser::User(uid));
        proc.Command(LinuxParser::Command(pids[i]));
        proc.Ram(LinuxParser::Ram(pids[i]));
        proc.UpTime(LinuxParser::UpTime(pids[i]));

        processes_.push_back(proc);
    }
}

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() { return processes_; }

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() {
    return LinuxParser::Kernel();
}

// TODO: Return the system's memory utilization
float System::MemoryUtilization() {
    return LinuxParser::MemoryUtilization();
}

// TODO: Return the operating system name
std::string System::OperatingSystem() {
    return LinuxParser::OperatingSystem();
}

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() {
    return LinuxParser::RunningProcesses();
}

// TODO: Return the total number of processes on the system
int System::TotalProcesses() {
    return LinuxParser::TotalProcesses();
}

// TODO: Return the number of seconds since the system started running
long int System::UpTime() {
    return LinuxParser::UpTime();
}