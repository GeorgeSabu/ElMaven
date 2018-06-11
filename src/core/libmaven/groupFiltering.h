#ifndef GROUPFILTERING_H
#define GROUPFILTERING_H

#include <iostream>

#include "mavenparameters.h"
#include "PeakGroup.h"

using namespace std;

class GroupFiltering
{

  public:
	/**
	 * @brief Constructor of class GroupFiltering
	 * @param mavenParameters Pointer to class MavenParameters
	 * @see MavenParameters
	 * @see PeakGroup
	 */

	vector<vector<float>> vector_intensity_array;
	vector<float> vector_mz_array;
	vector<float> vector_rt_array;

    GroupFiltering(MavenParameters *mavenParameters);

	/**
	 * @brief Constructor of class GroupFiltering
	 * @param mavenParameters Pointer to class MavenParameters
	 * @param slice Pointer to class mzSlice
	 * @see MavenParameters
	 * @see PeakGroup
	 * @see mzSlice
	 */
    GroupFiltering(MavenParameters *mavenParameters, mzSlice* slice);

    void filter(vector<PeakGroup> &peakgroups);

	bool filter(PeakGroup &peakgroup);

	/**
	 * [apply peak selection filters to group; if x percentage of peaks in the group are above the user input threshold for a parameter, do not reject the group]
	 * @method quantileFilters
	 * @param  group        [pointer to PeakGroup]
	 * @return [True if group has to be rejected, else False]
	 */
	bool quantileFilters(PeakGroup *group);

	void deleteDuplicateGroup();

  private:
		mzSlice *_slice;
    MavenParameters *_mavenParameters;

};

#endif //GROUPFILTERING_H