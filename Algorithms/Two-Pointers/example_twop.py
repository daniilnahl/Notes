# Given two integer arrays nums1 and nums2, sorted in non-decreasing order, return the minimum integer common to both arrays. If there is no common integer amongst nums1 and nums2, return -1.
# Note that an integer is said to be common to nums1 and nums2 if both arrays have at least one occurrence of that integer.
def getCommon(nums1, nums2):
        i = 0  # pointer for nums1
        j = 0  # pointer for nums2

        # This alone line is going to reduce the runtime .....
        if nums1[-1] < nums2[0] or nums2[-1] < nums1[0]:
            return -1

        # Two pointers approach
        while i < len(nums1) and j < len(nums2):
            if nums1[i] == nums2[j]:
                return nums1[i]
            elif nums1[i] <= nums2[j]:
                i += 1
            elif nums1[i] >= nums2[j]:
                j += 1

        return -1