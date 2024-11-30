# qq8e-DB
A solution to bidirectional query qq8e or such similar offline binding database.

Download qq8e from [here](https://github.com/qq8e/qq) or the torrent `db.torrent` .

This database actually contains 719753326 key-values. Traditional databases cannot handle it properly.

Here is a new solution via `Binary Indexed Tree` supporting bidirectional query taking only `6.1GiB` disk space.

## How to use
Unpack the origin text file to `6.9.txt`. Then run `encode.cpp`,`map.cpp`,`zip.cpp`,`basesort.cpp`,`BITencode.cpp`,`numencode.cpp`,`basesort.cpp`,`numdecode.cpp` in order.

Query via `qb.cpp`.

All the codes above can be compiled by `g++ *.cpp -o *.exe` without any other configures or profiles.
