
DIRS	= `ls | grep section`
EXTRAS = StanfordCPPLib
TARGET = snapshot.zip

.SILENT: clean

all: submit

submit: clean
	zip -y -r $(TARGET) $(EXTRAS) $(DIRS)

clean:
	-rm $(TARGET)
	-for d in $(DIRS); do (cd $$d; $(MAKE) clean ); done

