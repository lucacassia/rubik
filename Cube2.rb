#!/usr/bin/env ruby

class Cube2
    attr_accessor :state
 
    def initialize(f,u,r,b,d,l)
        @state = [f,u,r,b,d,l]
    end

    def f!
        tmp = @state[1][3]
        @state[1][3] = @state[5][2]
        @state[5][2] = @state[4][1]
        @state[4][1] = @state[2][0]
        @state[2][0] = tmp

        tmp = @state[1][0]
        @state[1][0] = @state[5][3]
        @state[5][3] = @state[4][2]
        @state[4][2] = @state[2][1]
        @state[2][1] = tmp

        tmp = @state[0][0]
        @state[0][0] = @state[0][3]
        @state[0][3] = @state[0][2]
        @state[0][2] = @state[0][1]
        @state[0][1] = tmp

        return self
    end

    def u!
        tmp = @state[0][1]
        @state[0][1] = @state[2][1]
        @state[2][1] = @state[3][1]
        @state[3][1] = @state[5][1]
        @state[5][1] = tmp

        tmp = @state[0][2]
        @state[0][2] = @state[2][2]
        @state[2][2] = @state[3][2]
        @state[3][2] = @state[5][2]
        @state[5][2] = tmp

        tmp = @state[1][0]
        @state[1][0] = @state[1][3]
        @state[1][3] = @state[1][2]
        @state[1][2] = @state[1][1]
        @state[1][1] = tmp

        return self
    end

    def r!
        tmp = @state[0][2]
        @state[0][2] = @state[4][2]
        @state[4][2] = @state[3][0]
        @state[3][0] = @state[1][2]
        @state[1][2] = tmp

        tmp = @state[0][3]
        @state[0][3] = @state[4][3]
        @state[4][3] = @state[3][1]
        @state[3][1] = @state[1][3]
        @state[1][3] = tmp

        tmp = @state[2][0]
        @state[2][0] = @state[2][3]
        @state[2][3] = @state[2][2]
        @state[2][2] = @state[2][1]
        @state[2][1] = tmp

        return self
    end

    def f
        tmp = Marshal.load(Marshal.dump(self))
        tmp.f!
    end

    def u
        tmp = Marshal.load(Marshal.dump(self))
        tmp.u!
    end

    def r
        tmp = Marshal.load(Marshal.dump(self))
        tmp.r!
    end

    def is_solved
        return @state[0][0]==@state[0][1]&&@state[0][1]==@state[0][2]&&@state[0][2]==@state[0][3]&&@state[0][3]==@state[0][0] &&
               @state[1][0]==@state[1][1]&&@state[1][1]==@state[1][2]&&@state[1][2]==@state[1][3]&&@state[1][3]==@state[1][0] &&
               @state[2][0]==@state[2][1]&&@state[2][1]==@state[2][2]&&@state[2][2]==@state[2][3]&&@state[2][3]==@state[2][0] &&
               @state[3][0]==@state[3][1]&&@state[3][1]==@state[3][2]&&@state[3][2]==@state[3][3]&&@state[3][3]==@state[3][0] &&
               @state[4][0]==@state[4][1]&&@state[4][1]==@state[4][2]&&@state[4][2]==@state[4][3]&&@state[4][3]==@state[4][0] &&
               @state[5][0]==@state[5][1]&&@state[5][1]==@state[5][2]&&@state[5][2]==@state[5][3]&&@state[5][3]==@state[5][0]
    end

    def to_s
        "\n     "+@state[1][1]+" "+@state[1][2]+"\n"+
        "     "+@state[1][0]+" "+@state[1][3]+"\n"+
        " "+@state[5][1]+" "+@state[5][2]+" "+@state[0][1]+" "+@state[0][2]+" "+@state[2][1]+" "+@state[2][2]+" "+@state[3][1]+" "+@state[3][2]+"\n"+
        " "+@state[5][0]+" "+@state[5][3]+" "+@state[0][0]+" "+@state[0][3]+" "+@state[2][0]+" "+@state[2][3]+" "+@state[3][0]+" "+@state[3][3]+"\n"+
        "     "+@state[4][1]+" "+@state[4][2]+"\n"+
        "     "+@state[4][0]+" "+@state[4][3]+"\n\n"
    end
 
end

c = Cube2.new("wgbw","rrrr","gwgg","yyyy","pppp","bbwb")
puts c.to_s

## start
tmp = Marshal.load(Marshal.dump(c))
while !tmp.is_solved
    tmp = Marshal.load(Marshal.dump(c))
    13.times do
        case Random.rand(7)
            when 0
                tmp.f!
                print "f "
            when 1
                tmp.u!
                print "u "
            when 2
                tmp.r!
                print "r "
            when 3
                tmp.f!.f!.f!
                print "F "
            when 4
                tmp.u!.u!.u!
                print "U "
            when 5
                tmp.r!.r!.r!
                print "R "
        end
    end
    puts "\n"
end

puts "That's it!\n"

puts tmp.to_s
