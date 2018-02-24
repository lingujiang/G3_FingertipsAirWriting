-- Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.
-- --------------------------------------------------------------------------------
-- Tool Version: Vivado v.2017.2 (win64) Build 1909853 Thu Jun 15 18:39:09 MDT 2017
-- Date        : Sat Feb 24 11:07:17 2018
-- Host        : SFB520WS13 running 64-bit Service Pack 1  (build 7601)
-- Command     : write_vhdl -force -mode synth_stub
--               w:/ECE532/ece532_project/ece532_project.srcs/sources_1/bd/design_1/ip/design_1_frame_average_buffer_0_1/design_1_frame_average_buffer_0_1_stub.vhdl
-- Design      : design_1_frame_average_buffer_0_1
-- Purpose     : Stub declaration of top-level module interface
-- Device      : xc7a100tcsg324-1
-- --------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity design_1_frame_average_buffer_0_1 is
  Port ( 
    pclk : in STD_LOGIC;
    reset : in STD_LOGIC;
    vsync : in STD_LOGIC;
    capture_address : in STD_LOGIC_VECTOR ( 16 downto 0 );
    capture_data : in STD_LOGIC_VECTOR ( 15 downto 0 );
    avg_addr_out : out STD_LOGIC_VECTOR ( 16 downto 0 );
    avg_data_out : out STD_LOGIC_VECTOR ( 15 downto 0 );
    avg_data_valid : out STD_LOGIC
  );

end design_1_frame_average_buffer_0_1;

architecture stub of design_1_frame_average_buffer_0_1 is
attribute syn_black_box : boolean;
attribute black_box_pad_pin : string;
attribute syn_black_box of stub : architecture is true;
attribute black_box_pad_pin of stub : architecture is "pclk,reset,vsync,capture_address[16:0],capture_data[15:0],avg_addr_out[16:0],avg_data_out[15:0],avg_data_valid";
attribute X_CORE_INFO : string;
attribute X_CORE_INFO of stub : architecture is "frame_average_buffer,Vivado 2017.2";
begin
end;