#pragma once

#include <iostream>
#include <iomanip>
#include "IBDmix/IBD_Stack.h"
#include "IBDmix/Genotype_Reader.h"

class Recorder{
    public:
        virtual void writeHeader(std::ostream &output) const = 0;
        virtual void initializeSegment() = 0;
        virtual void record(IBD_Node *node) = 0;
        virtual void report(std::ostream &output) const = 0;
};

class CountRecorder : public Recorder{
    private:
        int in_mask, maf_low, maf_high, rec_2_0,
            rec_0_2, sites, both, positive_lod;
    public:
        void writeHeader(std::ostream &output) const;
        void initializeSegment();
        void record(IBD_Node *node);
        void report(std::ostream &output) const;
};

class SiteRecorder : public Recorder{
    private:
        std::vector<unsigned long int> positions;

    public:
        void writeHeader(std::ostream &output) const;
        void initializeSegment();
        void record(IBD_Node *node);
        void report(std::ostream &output) const;
};
