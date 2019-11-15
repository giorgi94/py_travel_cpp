from os.path import abspath, normpath, isdir

from .lib import _travel


def travel(dirname: str):
    path = abspath(normpath(dirname))
    if isdir(path):
        return _travel(path)
    return []
