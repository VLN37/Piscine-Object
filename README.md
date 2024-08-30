I'll try to update this with my study notes.

I made this python CLI that may help people doing the project.

### CLI Guide

#### Features

- A cli for you to streamline the piscine boilerplate, Makefiles and default files.
- A set of suggested extensions.
- VSCode configurations to kickstart your formatter and linter customizations.

```console
# Download the attached asset
wget https://github.com/VLN37/Piscine-Object/releases/download/v1.0.1/turbo_piscine.tar.gz
# extract the files
tar -xzf turbo_piscine.tar.gz
# required permissions
chmod a+x cli.py
#  create your first module with this example
./cli.py create encapsulation ex00
```

### UML

```mermaid

classDiagram
direction TB
Worker *-- Position: composition
Worker *-- Statistic: composition

class Position {
    +int x
    +int y
    +int z
}

class Statistic {
    +int level
    +int exp
}

Workshop <-- Tool: association
Tool <--> "1" Worker: association

class Worker {
    %%composition
    +Position pos
    %%composition
    +Statistic stat
    %%aggregation
    +Tool tool

    +work()
    +GetTool~Tool~()
}


Tool<|--Hammer: inheritance
Tool<|--Shovel: inheritance

class Tool {
    <<abstract>>
    +use()
}

%%inheritance
class Shovel {
    +size_t numberOfUses
}

%%inheritance
class Hammer {
    +size_t numberOfUses
}

Workshop o-- Worker: aggregation
%%association
class Workshop {
    -multimap~Worker, Workshop~ workshopmap$
    -vector~Workers~ workers

    +executeWorkDay()
}
```
