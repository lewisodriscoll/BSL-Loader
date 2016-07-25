BSL Loader
----------

WIP code to read 2D `BSL
<http://www.diamond.ac.uk/Beamlines/Soft-Condensed-Matter/small-angle/
SAXS-Software/CCP13/BSL.html>`_ files into a python numpy array.

Reading binary files of this size in python seems to be very slow, so a C
extension is used to load the requried data into memory.
