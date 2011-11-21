#ifndef HEMELB_REPORTER_H
#define HEMELB_REPORTER_H

#include <string>
#include "configuration/SimConfig.h"
#include "configuration/CommandLine.h"
#include "log/Logger.h"
#include "util/fileutils.h"
#include "reporting/Timers.h"
namespace hemelb{
  namespace reporting {
    class Reporter {
      public:
        Reporter(bool doio, const std::string &name, std::string &inputFile);
        ~Reporter();
        void Cycle();
        void TimeStep(){timestep_count++;}
        void Image();
        void Snapshot();
        void Phase1(long int site_count, bool unstable,
                    Timers &timings);
        void ProcessorTimings(std::string *const names,double *const mins,double *const means,double *const maxes);
      private:
        FILE *ReportFile(){
            return mTimingsFile;
        }
        bool doIo;
        FILE *mTimingsFile;
        unsigned int cycle_count;
        unsigned int snapshot_count;
        unsigned int image_count;
        unsigned long int timestep_count;
    };
  }
}

#endif
