#include <common.h>
#include <command.h>
#include <environment.h>
#include <diag_struct.h>
extern int test_entry(unsigned long action_id);

int do_low_power(cmd_tbl_t * cmdtp, int flag, int argc, char *argv[])
{
    unsigned long test_id;
    if (argc < 2) {
	cmd_usage(cmdtp);    
        return 1;
    }
    test_id = simple_strtoul(argv[1], NULL, 16);
#ifdef CONFIG_LAB126_LPM_TEST
	switch(test_id)
	{
            case TEST_ID_IDLE_MODE:
	   	printf("Entering Idle mode...\n");
		break;
            case TEST_ID_SUSPEND_MODE:
	        printf("Entering Suspend mode...\n");
		break;
            case TEST_ID_SHIPPING_MODE:
	   	printf("Entering Shipping mode...\n");
		break;
	    default:
	   	cmd_usage(cmdtp);
	        return 0;
	}
    test_entry(test_id);
#endif    
    return 0;
}

U_BOOT_CMD(
	lpm, 2, 1, do_low_power,
	"Exercise Low Power modes in iMX6SL",
	"lpm <test number> :options are 1 2 or 3 - 1=Enter Idle mode(ARM WFI), 2=Enter Suspend mode, 3=Enter Ship mode\n");

