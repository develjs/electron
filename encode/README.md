# Encode asar package files

Now used simple XOR algorithm
For apply encoding use ASAR_ENCODE_KEY enviriment variable while bootstrap'ing (bootstrap.py -v) and build'ing (build.py -c D)
ASAR_ENCODE_KEY may be 0..255

Example:

```sh
export ASAR_ENCODE_KEY=123
script/bootstrap.py -v
export ASAR_ENCODE_KEY=123
script/build.py -c D
```