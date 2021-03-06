#ifndef DWL__LOCOMOTION__HIERARCHICAL_PLANNING__H
#define DWL__LOCOMOTION__HIERARCHICAL_PLANNING__H

#include <dwl/locomotion/PlanningOfMotionSequence.h>


namespace dwl
{

namespace locomotion
{

/**
 * @class HierarchicalPlanning
 * @brief HierarchicalPlanning is an abstract class that solves the problem of planning of motion
 * sequences using a hierarchical approach. This class derived from PlanningOfMotionSequence that
 * has the required information for a decoupled planning.
 */
class HierarchicalPlanning : public PlanningOfMotionSequence
{
	public:
		/** @brief Constructor function */
		HierarchicalPlanning();

		/** @brief Destructor function */
		~HierarchicalPlanning();

		/**
		 * @brief Initializes of the hierarchical planning
		 * @return bool True if was initialized the hierarchical planning
		 */
		virtual bool init();

		/**
		 * @brief Computes a whole-body motion provided for the hierarchical planning
		 * @param Pose current_pose Current pose
		 * @return True if it was computed the plan
		 */
		bool compute(Pose current_pose);
};

} //@namespace locomotion
} //@namespace dwl

#endif
