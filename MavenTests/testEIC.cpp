#include "testEIC.h"
#include "../libmaven/mavenparameters.h"
#include "../libmaven/mzSample.h"

TestEIC::TestEIC() {
    loadFile = "/home/rajat/elucidata/maven/maven_opensource/bin/methods/bk_#sucyxpe_1_9.mzxml";
    blankSample = "/home/rajat/elucidata/maven/maven_opensource/bin/methods/blan_#sucyxpe_2_4.mzxml";
}

void TestEIC::initTestCase() {
    // This function is being executed at the beginning of each test suite
    // That is - before other tests from this class run
    //MavenParameters* mavenparemeters = new MavenParameters();
    //mavenparemeters->printSettings();
}

void TestEIC::cleanupTestCase() {
    // Similarly to initTestCase(), this function is executed at the end of test suite
}

void TestEIC::init() {
    // This function is executed before each test
}

void TestEIC::cleanup() {
    // This function is executed after each test
}

void TestEIC::testFileLoad() {
    mzSample mzsample;
    mzsample.loadSample(loadFile);
    QVERIFY(true);
}

void TestEIC:: testIsAllScansParsed() {
    mzSample mzsample;
    unsigned int numberOfScans = 1603;
    mzsample.parseMzXML(loadFile);
    QVERIFY(mzsample.scanCount() == numberOfScans);
}

void TestEIC:: testScanParsing() {
    mzSample mzsample;
    unsigned int scanNum = 1;
    int scannum = 1;
    float rt = 0.493428 / 60.0;
    int msLevel = 1;
    int polarity = 1;
    float basePeakMz = 258.96;
    float precursorMz = 0.0;
    float collisionEnergy = 0.0;
    bool centroided = false;
    string filterLine = "FTMS + p ESI Full ms [70.00-770.00]";
    string scanType = "Full";
    unsigned int peakCount  = 918;
    
    mzsample.parseMzXML(loadFile);
    Scan* scan = mzsample.getScan(scanNum);

    QVERIFY(scan->rt == rt);

    QVERIFY(scan->scannum == scannum);

    QVERIFY(scan->mslevel == msLevel);

    QVERIFY(scan->polarity == polarity);

    QVERIFY(scan->precursorMz == precursorMz);

    QVERIFY(scan->productMz == basePeakMz);

    QVERIFY(scan->collisionEnergy == collisionEnergy);
    
    QVERIFY(scan->centroided == centroided);

    QVERIFY(scan->filterLine == filterLine);

    QVERIFY(scan->scanType == scanType);

    QVERIFY(scan->mz.size() == peakCount);

    QVERIFY(scan->intensity.size() == peakCount);
    
}

void TestEIC:: testSrmScan() {
    mzSample mzsample;
    unsigned int numberOfScans = 1603;
    mzsample.loadSample(loadFile);

    map<string,vector<int> >::iterator itr = mzsample.srmScans.begin();

    QVERIFY(itr->first.compare("FTMS + p ESI Full ms [70.00-770.00]") == 0 );

    unsigned int k = mzsample.srmScans.find(itr->first)->second.size();

    QVERIFY(k == numberOfScans);
}

void TestEIC:: testMinMaxMz() {
    mzSample mzsample;
    float minMz = 70.0012;
    float maxMz = 769.953;
    mzsample.loadSample(loadFile);

    QVERIFY(common::floatCompare(mzsample.minMz, minMz));

    QVERIFY(common::floatCompare(mzsample.maxMz, maxMz));

}

void TestEIC:: testMinMaxRT() {
    mzSample mzsample;
    float minRT = 0.00201776666;
    float maxRT = 7.20475;
    mzsample.loadSample(loadFile);

    QVERIFY(common::floatCompare(mzsample.minRt, minRT));

    QVERIFY(common::floatCompare(mzsample.maxRt, maxRT));

}

void TestEIC:: testSampleName() {
    mzSample mzsample;
    string sampleName = "bk_#sucyxpe_1_9";
    mzsample.loadSample(loadFile);

    QVERIFY(sampleName.compare(mzsample.sampleName) == 0);
}

void TestEIC:: testBlankSample() {
    mzSample mzsample;
    mzsample.loadSample(blankSample);
    QVERIFY(mzsample.isBlank);

    mzsample.loadSample(loadFile);
    QVERIFY(!mzsample.isBlank);
}
