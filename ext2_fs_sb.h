#ifndef __EXT_SB_INFO__
#define __EXT_SB_INFO__

//structure used to store the super block information 

struct ext2_sb_info {
__u32 s_frag_size; /* Size of a fragment in bytes */
__u32 s_frags_per_block;/* Number of fragments per block */
__u32 s_inodes_per_block;/* Number of inodes per block */
__u32 s_frags_per_group;/* Number of fragments in a group */
__u32 s_blocks_per_group;/* Number of blocks in a group */
__u32 s_inodes_per_group;/* Number of inodes in a group */
__u32 s_itb_per_group; /* Number of inode table blocks per  group */
__u32 s_gdb_count; /* Number of group descriptor blocks */
__u32 s_desc_per_block; /* Number of group descriptors per block */
__u32 s_groups_count; /* Number of groups in the fs */
struct buffer_head * s_sbh; /* Buffer containing the super block */
struct ext2_super_block * s_es; /* Pointer to the super block in the buffer */
struct buffer_head ** s_group_desc;
__u16 s_loaded_inode_bitmaps;
__u16 s_loaded_block_bitmaps;
/*
__u32 s_inode_bitmap_number[EXT2_MAX_GROUP_LOADED];
struct buffer_head * s_inode_bitmap[EXT2_MAX_GROUP_LOADED];
__u32 s_block_bitmap_number[EXT2_MAX_GROUP_LOADED];
struct buffer_head * s_block_bitmap[EXT2_MAX_GROUP_LOADED];
*/
__u32 s_mount_opt;
uid_t s_resuid;
gid_t s_resgid;
__u16 s_mount_state;
__u16 s_pad;
__s32 s_addr_per_block_bits;
__s32 s_desc_per_block_bits;
__s32 s_inode_size;
__s32 s_first_ino;
};

#endif
