proftool:
	ghc --make Main.hs -o proftool -O

clean:
	rm *.hi *.o proftool

setup:
	cabal update
	cabal install binary
	cabal install parsec
	cabal install attoparsec
	cabal install regex-base
	cabal install regex-tdfa

.PHONY: clean setup proftool
