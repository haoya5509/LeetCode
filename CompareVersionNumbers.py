# Compare Version Numbers Total Accepted: 504 Total Submissions: 3809 My Submissions Question Solution 
# Compare two version numbers version1 and version1.
# If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.

# You may assume that the version strings are non-empty and contain only digits and the . character.
# The . character does not represent a decimal point and is used to separate number sequences.
# For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

# Here is an example of version numbers ordering:

# 0.1 < 1.1 < 1.2 < 13.37
# Credits:
# Special thanks to @ts for adding this problem and creating all test cases.
# Author:	haoya
# Time:		11:00PM	2014/12/16

__author__ = 'haoya5509'

def compareVersion(version1, version2):
    a = version1.split('.')
    b = version2.split('.')
    maxlen = max(len(a),len(b))
    for i in range(len(a),maxlen):
        a.append(0)
    for i in range(len(b),maxlen):
        b.append(0)
    for i in range(maxlen):
        if int(a[i]) < int(b[i]):
            return -1
        if int(a[i]) > int(b[i]):
            return 1
    return 0



if __name__ == '__main__':
    print compareVersion('1.0','1')